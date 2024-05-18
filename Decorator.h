#pragma once
#include <iostream>
using namespace std;

class Cake {		// Component interface
public:
	virtual string getDesc() const = 0;
	virtual double cost() const = 0;
};

class PlainCake : public Cake {			// Concrete component
public:
	string getDesc() const override { return "Plain cake!"; }
	double cost()	 const override { return 300.0; }
};

class CakeDecorator : public Cake {		// Abstract decorator
protected:
	Cake* m_cake;
public:
	CakeDecorator(Cake* c) : m_cake(c) { }
	string getDesc() const override { return m_cake->getDesc(); }
	double cost()	 const override	{ return m_cake->cost();	}
};

class IceCreamCakeDecorator : public CakeDecorator {
public:
	IceCreamCakeDecorator(Cake* c) : CakeDecorator(c) { }
	virtual string getDesc() const override { return m_cake->getDesc() + " .. with Ice cream"; }
	virtual double cost()	 const override { return m_cake->cost() + 200.0; }
};

class FruitsCakeDecorator : public CakeDecorator {
public:
	FruitsCakeDecorator(Cake* c) : CakeDecorator(c) { }
	virtual string getDesc() const override { return m_cake->getDesc() + " .. with Fruits"; }
	virtual double cost()	 const override { return m_cake->cost() + 100.0; }
};