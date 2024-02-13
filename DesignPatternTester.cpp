#include "DesignPatternTester.h"
#include "Factory.h"

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
