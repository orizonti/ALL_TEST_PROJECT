// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "CONCEPTS_TEST.h"
#include <vector>

using namespace std;

template<typename T>
concept Hashable = requires(T a)
{
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};
 
struct meow {};
 
// Constrained C++20 function template:
template<Hashable T>
void f(T) {}
//
// Alternative ways to apply the same constraint:
// template<typename T>
//     requires Hashable<T>
// void f(T) {}
//
// template<typename T>
// void f(T) requires Hashable<T> {}
//
// void f(Hashable auto /*parameterName*/) {}


int main(int argc, char* argv[])
{
    using std::operator""s; //string operator ""s return std::string
 
    f("abc"s);    // OK, std::string satisfies Hashable
    // f(meow{}); // Error: meow does not satisfy Hashable
}

