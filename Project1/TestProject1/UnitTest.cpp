#include "../Project1/myHeader.h"
#include "../Project1/Source.cpp"

#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;




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

vehicles vehicle;
cars car;
trucks truck;



namespace TestProject1
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//
			// TODO: Add test logic here
			//
			Assert::AreEqual(50000, vehicle.BMW, 1);

			Assert::AreEqual(60000, vehicle.jaguar, 1);

			Assert::AreEqual(100000, vehicle.lambo, 1);

			Assert::AreEqual(50000, vehicle.buy(vehicle.BMW), 1);
			Assert::AreEqual(60000, vehicle.buy(vehicle.jaguar), 1);
			Assert::AreEqual(100000, vehicle.buy(vehicle.lambo), 1);

			Assert::AreEqual(10000, car.nissan, 1);
			Assert::AreEqual(20000, car.toyota, 1);
			Assert::AreEqual(10000, car.honda, 1);

			//make sure function is from derived class
			Assert::AreEqual(30000, car.buy(car.nissan, car.toyota), 1);
			Assert::AreEqual(20000, car.buy(car.nissan, car.honda), 1);

			// make sure price is from derived class
			Assert::AreEqual(20000, truck.GMC, 1);
			Assert::AreEqual(10000, truck.ford, 1);
			Assert::AreEqual(20000, truck.dodge, 1);
			Assert::AreEqual(15000, truck.nissan, 1);
			Assert::AreEqual(25000, truck.toyota, 1);
			Assert::AreEqual(30000, truck.chevy, 1);
			Assert::AreEqual(100000, truck.lambo, 1);

			Assert::AreEqual(145000, truck.buy(truck.GMC, truck.toyota, truck.lambo), 1);
			Assert::AreEqual(70000, truck.buy(truck.nissan, truck.toyota, truck.chevy), 1);
			Assert::AreEqual(140000, truck.buy(truck.nissan, truck.toyota, truck.lambo), 1);
			Assert::AreEqual(90000, truck.buy(car.nissan, vehicle.jaguar, truck.GMC), 1);
		};
	};
}
