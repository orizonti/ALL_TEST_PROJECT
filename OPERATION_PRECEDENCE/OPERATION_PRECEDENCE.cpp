// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "OPERATION_PRECEDENCE.h"
#include <iostream>
 
using namespace std;
//PREDECENE
//a*b   a/b   a%b	Multiplication, division, and remainder
//a+b   a-b	Addition and subtraction

int main(int argc, char* argv[])
{
     cout << "5*3/2: " << 5*3/2 <<endl;
     cout << "5+3/2: " << 5+3/2 <<" | " << "5+3.0/2: " << 5+3.0/2 <<endl;
     cout << "5+3*2: " << 5+3*2 <<endl;
    
}

