#pragma once
#include <iostream>
using namespace std;

class Waiter_Subsystem1 {
public:
	void writeOrder()		{ cout << "Writing client's order..." << endl; }
	void serveCustomer()	{ cout << "Serving client..." << endl; }
};

class Kitchen_Subsystem2 {
public:
	void prepareFood()	{ cout << "Preparing food..." << endl; }
	void washDishes()	{ cout << "Washing dishes..." << endl; }
};

class Order_Facade {
	Waiter_Subsystem1		m_waiter;
	Kitchen_Subsystem2		m_kitchen;
public:
	void orderFood() {
		m_waiter.writeOrder();
		m_kitchen.prepareFood();
		m_waiter.serveCustomer();
		m_kitchen.washDishes();
	}
};
