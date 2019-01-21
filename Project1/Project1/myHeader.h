
#pragma once
#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here


class vehicles      // base-class
{
public:
	float nissan;  // both vehicles
	float toyota;  // both vehicles
	float honda;
	float GMC;
	float ford;
	float dodge;
	float chevy;

	float BMW = 50000;
	float jaguar = 60000;
	float lambo = 100000;

	// expect new definitions
	virtual float buy(float a)
	{
		float c = a;
		return c;
	}

};

// derived classes

class cars : vehicles
{
public:
	float buy(float a, float b)   // new definition
	{
		float sum1 = a + b;
		return sum1;
	};

	float nissan = 10000;  // nissan car
	float toyota = 20000;	 // toyota car
	float honda = 10000;
};


class trucks : vehicles
{
public:
	float buy(float a, float b, float c)   // new definition
	{
		float sum2 = a + b + c;
		return sum2;
	};


	float GMC = 20000;
	float ford = 10000;
	float dodge = 20000;
	float nissan = 15000;  // nissan truck
	float toyota = 25000;  // toyota truck
	float chevy = 30000;
	// use base-class value
	using vehicles::lambo;

};

// objects
vehicles vehicle;
cars car;
trucks truck;

