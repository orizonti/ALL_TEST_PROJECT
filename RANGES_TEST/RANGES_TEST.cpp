// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "RANGES_TEST.h"
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <ranges>
#include <iomanip>
#include <type_traits>

#include <format>
#include <iostream>
#include <chrono>

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
     
    //==========
    for(auto val: ret) std::cout << val; 
    std::cout << endl;
    //=========================================================================
}


void TEST_RANGES_FUNCTION2_STL()
{
const std::string text { "    Hello World" };
std::cout << std::quoted(text) << '\n';

auto firstNonSpace = std::find_if_not(text.begin(), text.end(), ::isspace);
std::string temp(firstNonSpace, text.end());
std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    
std::cout << std::quoted(temp) << '\n';


}

void TEST_RANGES_FUNCTION2_RANGES()
{
const std::string text { "    Hello World" };
std::cout << std::quoted(text) << '\n';

auto conv = std::ranges::transform_view { 
    std::ranges::drop_while_view{text, ::isspace}, 
    ::toupper 
};

std::string temp(conv.begin(), conv.end());

std::cout << std::quoted(temp) << '\n';
}

void TEST_RANGES_FUNCTION_DROP_VIEW()
{
  const auto nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 
    for (int i : nums | std::views::drop(2))
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1, 8) | std::views::drop(2))
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::ranges::drop_view{nums, 2})
        std::cout << i << ' ';
    std::cout << '\n';
}

//if C is a range adaptor object and R is a viewable_range, 
//these two expressions are equivalent: C(R) and R | C.
void TEST_RANGES_FUNCTION_ADAPTORS()
{
const std::vector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

auto even = [](int i) { return 0 == i % 2; };
 
namespace sv = std::views;
for(auto& i : numbers | sv::filter(even) | sv::drop(1) | sv::reverse) 
    std::cout << i << ' '; 
}

void TEST_RANGES_FUNCTION_IOTA_VIEW()
{
for (int i : std::ranges::iota_view{1, 10})
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';
 
    struct Bound
    {
        int bound;
        bool operator==(int x) const { return x == bound; }
    };
    for (int i : std::views::iota(1, Bound{10}))
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1) | std::views::take(9))
        std::cout << i << ' ';
    std::cout << '\n';
 
    std::ranges::for_each(std::views::iota(1, 10), [](int i) {
        std::cout << i << ' ';
    });
    std::cout << '\n';

    for (int i : std::views::iota(1))
    {
        std::cout << i << ' '; if(i == 20) break;
    }

    std::cout << '\n';
}


int main(int argc, char* argv[])
{
    //TEST_RANGES_FUNCTION1();
    //TEST_RANGES_FUNCTION2_RANGES();
    //TEST_RANGES_FUNCTION_DROP_VIEW();
    //TEST_RANGES_FUNCTION_ADAPTORS();
    TEST_RANGES_FUNCTION_IOTA_VIEW();


    //auto val = 2.0 / 2 *3;
    //cout << boolalpha;
    //cout << "IS FLOAT POINT - " << std::is_floating_point<decltype(val)>::value;

}

