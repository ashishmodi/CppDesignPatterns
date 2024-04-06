#include "DesignPatternTester.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Singleton.h"

void DesignPatternTester::testFactory() {
	cout << "*** Factory pattern ***" << endl;
	Factory::ShapeFactory* circleFactory = new Factory::CircleFactory();
	Factory::ShapeFactory* squareFactory = new Factory::SquareFactory();

	Factory::Shape* circle = circleFactory->createShape();
	Factory::Shape* square = squareFactory->createShape();

	circle->draw();
	square->draw();

	delete circleFactory;
	delete squareFactory;
	delete circle;
	delete square;
	cout << endl;
}

void DesignPatternTester::testAbstractFactory() {
	cout << "*** Abstract factory pattern ***" << endl;
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
	cout << endl;
}

void DesignPatternTester::testBuilder() {
	cout << "*** Builder pattern ***" << endl;
	ComputerAssembler assembler;
	Computer computer;

	assembler.setBuilderType(new DesktopComputerBuilder());
	computer = assembler.assembleComputer();
	cout << "Desktop Computer specification:" << endl;
	computer.display();

	assembler.setBuilderType(new LaptopComputerBuilder());
	computer = assembler.assembleLaptop();
	cout << "Laptop Computer specification:" << endl;
	computer.display();
}

// using namespace Prototype;
void DesignPatternTester::testPrototype() {
	cout << "*** Prototype pattern ***" << endl;
	Prototype::Circle circleProto(5.0);
	Prototype::Rectangle rectangleProto(4.0, 6.0);

	Prototype::Shape* circle = circleProto.clone();
	Prototype::Shape* rectangle = rectangleProto.clone();

	circle->draw();
	rectangle->draw();

	delete circle;
	delete rectangle;
}

void DesignPatternTester::testSingleton() {
	cout << "*** Prototype pattern ***" << endl;
	Configuration& config = Configuration::getInstance();
	config.initConfigs();
}
