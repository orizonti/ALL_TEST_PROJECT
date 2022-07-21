// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "STD_THREAD_TEST.h"
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

void MainWork()
{

    for( size_t i = 0; i < 5; i++)
    {
        cout << "THREAD ID - " << this_thread::get_id() << " MAIN WORK" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    } 
}

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

std::mutex mtx;
void Print(char ch)
{
    mtx.lock();
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx.unlock();
}
void PrintWithGuardLock(char ch)
{
    lock_guard<mutex> guard(mtx);
    
    //unique_lock<mutex> guard2(mtx, std::defer_lock); //unique_lock permit arbitrary lock unlock
    //guard2.lock();

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
}

void TestMutexSynchronization()
{
   cout << "TEST MUTEX SYNCHRONIZATION" << endl;
   //thread t1(Print,'*');
   //thread t2(Print,'#');

   thread t1(PrintWithGuardLock,'*');
   thread t2(PrintWithGuardLock,'#');
   t1.join();
   t2.join();
   cout << "===================" << endl;

}


std::recursive_mutex rec_mtx;
void RecursivePrint(int a)
{
    rec_mtx.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(200));

    if( a <= 1)
    {
        cout << endl;
        rec_mtx.unlock();
        return;
    }

    a--;
    RecursivePrint(a);
    rec_mtx.unlock();
}

void TestRecursiveMutex()
{
   cout << "TEST RECURSIVE MUTEX" << endl;
    thread t1(RecursivePrint,10);
    thread t2(RecursivePrint,10);
    t1.join();
    t2.join();
   cout << "===================" << endl;
}

void TestReturnByReferenceThread()
{
    //===================================================
    cout << "TEST THREAD RETURN REF";
    int output = 0; thread t1(TestPow,2,ref(output));
    cout << "RESULT - " << output << endl;
    cout << "===================" << endl;

    MainWork();
    
    t1.join();

    cout << "===================================================" << endl;
}

void TestReturnFromLambda()
{
    cout << "TEST THREAD RETURN FROM LAMBDA" << endl;

    int result = 0;
    thread t2( [&result](){ result = TestSum(3,4); } );
    t2.join();

    cout << "RESULT - " << result << endl;
    cout << "===================================================" << endl;
}

void TestInvokeClassMethodThread()
{
    cout << "TEST THREAD CLASS METHOD" << endl;

    MyClass TestObject;
    thread t3( [&TestObject](){ TestObject.DoWork(); } );
    thread t4( &MyClass::DoWork2, TestObject,2 );

    MainWork();
    t3.join(); 
    t4.join();
    cout << "===================================================" << endl;
}

 
int main()
{
  TestReturnByReferenceThread(); 
  TestReturnFromLambda();
  TestInvokeClassMethodThread();
  TestMutexSynchronization();
  TestRecursiveMutex();

}


void MyClass::DoWork()
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID thread :" << this_thread::get_id() << " MY CLASS DO WORK" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "ID thread :" << this_thread::get_id() << " MY CLASS STOPPED WORK" << endl;
 
}

void MyClass::DoWork2(int a)
{
    cout << "DO WORK 2 INPUT PARAMETER - " << a << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS DO WORK" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "ID thread :" << this_thread::get_id() << "MY CLASS STOPPED WORK" << endl;
 
}