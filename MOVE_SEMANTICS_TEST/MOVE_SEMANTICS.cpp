﻿// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//
#include "MOVE_SEMANTICS.h"
#include <vector>
// forward example
#include <utility>      // std::forward
#include <iostream>     // std::cout

using namespace std;


class MyClassTest
{
    public:
    MyClassTest(int x = 20): x(20){ cout << "DEFAULT CONSTR : " << x << endl;};
    MyClassTest(const MyClassTest& copy) { x = copy.x ;cout << "COPY CONSTR : " << x << endl; };
    int x;

    void operator=(const MyClassTest& copy)
    {
        this->x = copy.x;  
        cout << "OPERATOR= " << this->x << endl;
    }
};



// function with lvalue and rvalue reference overloads:
void overloaded (const int& x) {std::cout << "[lvalue]";}
void overloaded (int&& x) {std::cout << "[rvalue]";}

// function template taking rvalue reference to deduced type:
template <class T> void fn (T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::move(x));                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
  std::cout << endl;
}

 
int main()
{

  int a;

  std::cout << endl;
  std::cout << "calling fn with lvalue: "; fn (a);
  std::cout << "calling fn with rvalue: "; fn (0);
  std::cout << "calling fn with lvalue: "; fn (std::move(a));


  //cout << "============================" << endl;
  //MyClassTest t = 20;
  //cout << "-----------------" << endl;
  //MyClassTest t2 = MyClassTest(30);
  //cout << "-----------------" << endl;
  //MyClassTest t3 = t2;
  //cout << "============================" << endl;
  //cout << "COPY TEST" << endl;
  //t = t2;
  //cout << "============================" << endl;
  
  //cout << "VECTOR TEST" << endl;
  //std::vector<MyClassTest> vec; vec.reserve(2);
  //vec.push_back(MyClassTest()); vec.push_back(MyClassTest());
  //cout << "============================" << endl;
  //std::vector<MyClassTest> vec2{2,2,2,2,2};

  return 0;
}

