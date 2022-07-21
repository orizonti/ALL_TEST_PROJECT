// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "STD_THREAD_TEST.h"
#include <thread>
#include <chrono>

using namespace std;

void TestPow(int input, int &output) // return reslut by reference
{
    cout << "THREAD ID - " << this_thread::get_id() << " THREAD WORK" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    output = input * input;
    cout << "THREAD ID - " << this_thread::get_id() << " THREAD END" << endl;
}

int TestSum(int x, int y)
{
    return x + y;
}

class MyClass
{
    public:
    void DoWork();
    void DoWork2(int a);
};

void MainWork()
{

    for( size_t i = 0; i < 10; i++)
    {
        cout << "THREAD ID - " << this_thread::get_id() << " MAIN WORK" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    } 
}
 
int main()
{
    //===================================================
    cout << "TEST THREAD RETURN REF";
    int output = 0; thread t1(TestPow,2,ref(output));
    cout << "RESULT - " << output << endl;
    cout << "===================" << endl;

    MainWork();
    
    t1.join();

    cout << "===================================================" << endl;
    cout << "TEST THREAD RETURN FROM LAMBDA" << endl;

    int result = 0;
    thread t2( [&result](){ result = TestSum(3,4); } );
    t2.join();

    cout << "RESULT - " << result << endl;
    cout << "===================================================" << endl;

    cout << "TEST THREAD CLASS METHOD" << endl;

    MyClass TestObject;
    thread t3( [&TestObject](){ TestObject.DoWork(); } );
    thread t4( &MyClass::DoWork2, TestObject,2 );

    MainWork();
    t3.join(); 
    t4.join();
    cout << "===================================================" << endl;

}


void MyClass::DoWork()
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS DO WORK" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS STOPPED WORK" << endl;
 
}

void MyClass::DoWork2(int a)
{
    cout << "DO WORK 2 INPUT PARAMETER - " << a << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS DO WORK" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS STOPPED WORK" << endl;
 
}