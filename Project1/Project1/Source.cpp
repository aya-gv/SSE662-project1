// InheritanceProjectChapter15.cpp : Defines the entry point for the console application.
//

#include "myHeader.h" 

#include <iostream> 
#include <ostream> 

using namespace std;
using std::cout;
using std::endl;



int main()
{
	float sum1 = car.buy(car.nissan, car.honda);
	cout << sum1 << endl;

	float sum2 = truck.buy(truck.GMC, truck.dodge, truck.chevy);
	cout << sum2 << endl;

	float sum3 = truck.buy(truck.nissan, truck.toyota, truck.lambo);
	cout << sum3 << endl;

	return 0;
};