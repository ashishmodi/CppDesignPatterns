#pragma once
#include <iostream>
using namespace std;

namespace Prototype
{
	class Shape {	// Interface or Abstract base class
	public:
		virtual Shape* clone() const = 0;
		virtual void draw() const = 0;
		virtual ~Shape() { }
	};

	class Circle : public Shape {	// Concrete prototype class
		double m_dRadius;
	public:
		Circle(double dRadius) : m_dRadius(dRadius) { }
		Shape* clone() const override {
			return new Circle(*this);
		}
		void draw() const override { cout << "Circle radius: " << m_dRadius << endl; }
	};

	class Rectangle : public Shape { // Concrete prototype class
		double m_dWidth, m_dHeight;
	public:
		Rectangle(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight) { }
		Shape* clone() const override {
			return new Rectangle(*this);
		}
		void draw() const override { cout << "Rectangle width: " << m_dWidth << ", height: " << m_dHeight << endl; }
	};
}