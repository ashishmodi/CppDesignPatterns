#include "DesignPatternTester.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"

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
	cout << endl;
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
	cout << endl;
}

void DesignPatternTester::testSingleton() {
	cout << "*** Singleton pattern ***" << endl;
	Configuration& config = Configuration::getInstance();	// new instance created
	Configuration& config2 = Configuration::getInstance();	// no new instance here
	cout << "Day is: " << config.getValue("Day") << endl;
	cout << endl;
}

void DesignPatternTester::testAdapter() {
	cout << "*** Adapter pattern ***" << endl;
	DataReader dataReader;
	SDCard* sdCard = new SDCard(10);
	USB* usbAdapter = new SDCard_USB_Adapter(sdCard);
	dataReader.readDataFromStorage(usbAdapter);
	cout << endl;
}

void DesignPatternTester::testBridge() {
	cout << "*** Bridge pattern ***" << endl;
	Bridge::Red colorRed;
	Bridge::Blue colorBlue;
	Bridge::Circle circle(colorRed);
	Bridge::Square square(colorBlue);
	circle.draw();
	square.draw();
	cout << endl;
}

void DesignPatternTester::testComposite() {
	cout << "*** Composite pattern ***" << endl;
	SimpleNode* sNodeA = SimpleNode::createNode("simpleA", "sA");
	SimpleNode* sNodeB = SimpleNode::createNode("simpleB", "sB");
	ComplexNode* cNodeA = ComplexNode::createNode("cmplxA");
	ComplexNode* cNodeB = ComplexNode::createNode("cmplxB");
	ComplexNode* cNodeC = ComplexNode::createNode("cmplxC");
	cNodeA->appendNode(cNodeB);
	cNodeA->appendNode(cNodeC);
	cNodeB->appendNode(sNodeA);
	cNodeB->appendNode(sNodeB);

	list<Node*> nodes;
	nodes.push_back(ComplexNode::createNode("cmplx1"));
	nodes.push_back(ComplexNode::createNode("cmplx2"));
	list<Node*>::const_iterator begin = nodes.begin(), end = nodes.end();
	cout << endl;
}

void DesignPatternTester::testDecorator() {
	cout << "*** Decorator pattern ***" << endl;
	Cake* plainCake = new PlainCake();
	cout << plainCake->getDesc() << " .. costs Rs." << plainCake->cost() << endl;
	Cake* iceCreamCake = new IceCreamCakeDecorator(plainCake);
	cout << iceCreamCake->getDesc() << " .. costs Rs." << iceCreamCake->cost() << endl;
	Cake* fruitIceCreamCake = new FruitsCakeDecorator(iceCreamCake);
	cout << fruitIceCreamCake->getDesc() << " .. costs Rs." << fruitIceCreamCake->cost() << endl;
	delete plainCake;
	delete iceCreamCake;
	delete fruitIceCreamCake;
	cout << endl;
}

void DesignPatternTester::testFacade() {
	cout << "*** Facade pattern ***" << endl;
	Order_Facade orderFacade;
	orderFacade.orderFood();
	cout << endl;
}

void DesignPatternTester::testFlyweight() {
	cout << "*** Flyweight pattern ***" << endl;
	Game* game = new Game();
	// unique_ptr<Game> game = make_unique<Game>();
	game->addTree(1, 3, "green");
	game->addTree(2, 5, "brown");
}
