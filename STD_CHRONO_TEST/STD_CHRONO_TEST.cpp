// ALL_TEST_PROJECT.cpp: определяет точку входа для приложения.
//

#include "STD_CHRONO_TEST.h"
#include <chrono>

using namespace std;

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

