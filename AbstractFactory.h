#pragma once

#include <iostream>
using namespace std;

class Pizza {		// Abstract Product Interface
public:
	virtual void bake() = 0;
	virtual ~Pizza() { }
};

class NewYorkCheesePizza : public Pizza {
	public: void bake() override { cout << "Baking New York-style cheese pizza." << endl; }
};

class NewYorkPepperoniPizza : public Pizza {
	public: void bake() override { cout << "Baking New York-style pepperoni pizza." << endl; }
};

class MexicanCheesePizza : public Pizza {
	public: void bake() override { cout << "Baking Mexican-style cheese pizza." << endl; }
};

class MexicanPepperoniPizza : public Pizza {
	public: void bake() override { cout << "Baking Mexican-style pepperoni pizza." << endl; }
};

class PizzaFactory {	// Abstract Factory Interface
public:
	virtual Pizza* createCheesePizza() = 0;
	virtual Pizza* createPepperoniPizza() = 0;
};

class NewYorkPizzaFactory : public PizzaFactory {
public:
	Pizza* createCheesePizza() override		{ return new NewYorkCheesePizza(); }
	Pizza* createPepperoniPizza() override	{ return new NewYorkPepperoniPizza(); }
};

class MexicanPizzaFactory : public PizzaFactory {
public:
	Pizza* createCheesePizza() override		{ return new MexicanCheesePizza(); }
	Pizza* createPepperoniPizza() override	{ return new MexicanPepperoniPizza(); }
};