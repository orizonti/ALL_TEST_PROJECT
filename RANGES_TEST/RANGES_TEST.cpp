// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "RANGES_TEST.h"
#include <vector>
#include <functional>
#include <numeric>
#include <ranges>

using namespace std;
namespace ph = std::placeholders;

void operator<<(std::ostream os, vector<int> vec)
{
    for(auto val: vec) os << val;
    os << endl;
}

void TEST_RANGES_FUNCTION1()
{
    std::cout << "RANGES TEST" << std::endl;
    std::cout << "========================" << std::endl;
    auto const ints = {0,1,2,3,4,5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    //=========================================================================
    std::cout <<endl<< "PIPE SYNTAX OF COMPOSING THE VIEWS:" << endl;
    auto ret = ints | std::views::filter(even) | std::views::transform(square);

    for(auto val: ret) std::cout << val; 
    std::cout << endl;
    //=========================================================================
 
    //=========================================================================
    std::cout <<endl<< "TRADITIONAL FUNCTIONAL COMPOSING SYNTAX:" << endl;
    ret = std::views::transform(std::views::filter(ints, even), square) ;

    for(auto val: ret) std::cout << val; 
    std::cout << endl;
    //=========================================================================
}


int main(int argc, char* argv[])
{
    TEST_RANGES_FUNCTION1();
}

