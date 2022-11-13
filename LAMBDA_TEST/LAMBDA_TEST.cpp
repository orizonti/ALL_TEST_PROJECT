// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "LAMBDA_TEST.h"
#include <vector>
#include <functional>
#include <numeric>

using namespace std;
namespace ph = std::placeholders;

int operator|(int value, function<int(int)> f2)
{
     return f2(value);
}


int operator|(vector<int> vec, function<int(vector<int>)> f2)
{
     return std::accumulate(vec.begin(),vec.end(),0);
}

vector<int> operator|(vector<int> vec, function<vector<int>(vector<int>)> f2)
{
     return f2(vec);
}

function<int(int)> operator|(function<int(int)> f1, function<int(int)> f2)
{
     return [f1,f2](int value)->int{ return f2(f1(value)); };
}

int mult_two_func(int n)
{
    return n*2;
}

int main(int argc, char* argv[])
{
    function<int(int)> mult_two = [](int value) -> int {return 2*value;};

    function<int(int)> mult_three = [](int value) -> int {return 3*value;};

    function<int(vector<int>)> summ_vec = [](vector<int> vec) -> int {return std::accumulate(vec.begin(),vec.end(),0);};
    auto summ_vec_half = [](vector<int> vec) -> auto {vec.erase(vec.begin()+3,vec.end()); return vec;};

    auto a = {2,3,4,2,3,5,4,5}; 
    auto res = a | summ_vec_half | summ_vec;
    cout << "TEST SUMM VEC : " << res << endl;


    auto mult_six = mult_two | mult_three;

    cout << "TEST FUNC COMPOSE 2*n | 3*n     - :"<<3 <<" "<< mult_six(3) << endl;

    int value = 3 | mult_two | mult_three;
    cout << "TEST FUNC COMPOSE TWO 2*n | 3*n - :"<<3 <<" "<<value << endl;


    int value3 = mult_two_func(2) | mult_three;
    int value5 = operator|(3,mult_two_func);


    function<int(int)> mult_two_conv = mult_two_func;
    int value6 = 3 | mult_two_conv | mult_two_conv;

    cout << "TEST FUNC COMPOSE 3 | f2 | f2 : "<<3 <<" "<<value6 << endl;

    std::function<int(int)> test_f = mult_two_func;
    int value4 = value3 | test_f;
}

