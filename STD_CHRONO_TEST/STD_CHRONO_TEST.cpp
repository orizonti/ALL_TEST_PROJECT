// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "STD_CHRONO_TEST.h"
#include <chrono>

using namespace std;
class BaseClass
{
	public:
	int x = 2;
	int y = 3;
	int sum() { return x+y;};
};

class BaseClass2
{
	public:
	int x = 2;
	int y = 3;
	int sum() { return x*y;};
};

template<typename T>
class BaseClass3 : public T
{
	public:
	void print_data() { std::cout << sum() << endl;};
	int yy = 2;
};

class MyClass: public BaseClass3<BaseClass>
{
	public:
	MyClass(){ std::cout << "Class1 - "; print_data();};
	int zz = 3;
};

class MyClass2: public BaseClass3<BaseClass2>
{
	public:
	MyClass2(){ std::cout << "Class2 - "; print_data();};
	int xx2 = 20;
};

void TestTime(int Count)
{

	std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint = std::chrono::high_resolution_clock::now();


		for (int x = 0; x<Count; x = x + 4)
		{
			int t = 0;
			int y = 2;
			int z = t + y;

		}

		std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint2 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> Dur = TimePoint2 - TimePoint;
		std::cout << "Duration - " << Dur.count() <<"  count -    "<< Count << "\n";

};


int main(int argc, char* argv[])
{

	MyClass mm1; //mm1.print_data();
	MyClass2 mm2; //mm2.print_data();
	

	cout << "STD CHRONO TEST" << endl;
	TestTime(1000000);
	TestTime(2000000);
	TestTime(3000000);
	TestTime(4000000);
	TestTime(5000000);
	TestTime(6000000);
	TestTime(7000000);


	return 0;
}

