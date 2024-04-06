#pragma once

#include <iostream>
using namespace std;

namespace Factory
{
	class Shape {	// Abstract/Interface Product class
	public:
		virtual void draw() = 0;
		virtual ~Shape() {}
	};

	class Circle : public Shape {	// Concrete Product class
	public: void draw() override { cout << "Drawing a Circle." << endl; }
	};

	class Square : public Shape {	// Concrete Product class
	public: void draw() override { cout << "Drawing a Square." << endl; }
	};

	class ShapeFactory {			// Abstract creator class
	public:
		virtual Shape* createShape() = 0;
		virtual ~ShapeFactory() {}
	};

	class CircleFactory : public ShapeFactory {		// Concrete creator class
	public: Shape* createShape() override { return new Circle(); }
	};

	class SquareFactory : public ShapeFactory {		// Concrete creator class
	public: Shape* createShape() override { return new Square(); }
	};
}