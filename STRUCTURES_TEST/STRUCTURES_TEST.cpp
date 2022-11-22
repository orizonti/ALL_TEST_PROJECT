// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "STRUCTURES_TEST.h"
#include <iostream>
#include <vector>
 
using namespace std;

std::tuple<int, int, double> foo_tuple() 
{
  return {1, -1, 2.1};  // Error until N4387
}
int main(int argc, char* argv[])
{
    auto [v1,v2,v3] = foo_tuple();
    std::cout << " V1: " << v1 << " V2: " << v2 << " V3: " << v3 << endl;
    std::cout << "==========================";
    
    std::tuple<int,int,std::string> v = {2,3,"sdfsdf"};
    auto tt = std::make_tuple(2,4,"sdfsdf");

std::vector<std::pair<int, char const*>> roman
   {
      { 1000, "M" },{ 900, "CM" },
      { 500, "D" },{ 400, "CD" },
      { 100, "C" },{ 90, "XC" },
      { 50, "L" },{ 40, "XL" },
      { 10, "X" },{ 9, "IX" },
      { 5, "V" },{ 4, "IV" },
      { 1, "I" }
   };

   for(const auto [v,c]: roman)
    std::cout << "VALUE - " << v << " CHAR - " << c << endl;
}

