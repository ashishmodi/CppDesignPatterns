#include "DesignPatternTester.h"
#include "Factory.h"
#include "AbstractFactory.h"

void DesignPatternTester::testFactory() {
	ShapeFactory* circleFactory = new CircleFactory();
	ShapeFactory* squareFactory = new SquareFactory();

	Shape* circle = circleFactory->createShape();
	Shape* square = squareFactory->createShape();

	circle->draw();
	square->draw();

	delete circleFactory;
	delete squareFactory;
	delete circle;
	delete square;
}

void DesignPatternTester::testAbstractFactory() {
	PizzaFactory* nyFactory = new NewYorkPizzaFactory();
	Pizza* nyChessePizza = nyFactory->createCheesePizza();
	Pizza* nyPepperoniPizza = nyFactory->createPepperoniPizza();
	
	PizzaFactory* mexicanFactory = new MexicanPizzaFactory();
	Pizza* mexicanChessePizza = mexicanFactory->createCheesePizza();
	Pizza* mexicanPepperoniPizza = mexicanFactory->createPepperoniPizza();

	nyChessePizza->bake();			nyPepperoniPizza->bake();
	mexicanChessePizza->bake();		mexicanPepperoniPizza->bake();

	delete nyFactory;			delete nyChessePizza;			delete nyPepperoniPizza;
	delete mexicanFactory;		delete mexicanChessePizza;		delete mexicanPepperoniPizza;
}
