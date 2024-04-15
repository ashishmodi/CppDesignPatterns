#pragma once
#include <iostream>
using namespace std;

namespace Bridge {
	class Shape {		// Abstraction
	public:
		virtual void draw() = 0;
	};

	class Color {		// Implementation
	public:
		virtual void paint() = 0;
	};

	class Red : public Color {		// Concrete Implementation
	public:
		void paint() override { cout << "Red..." << endl; }
	};

	class Blue : public Color {		// Concrete Implementation
	public:
		void paint() override { cout << "Blue..." << endl; }
	};

	class Circle : public Shape {	// Concrete Abstraction
		Color& m_color;
	public:
		Circle(Color& color) : m_color(color) { }
		void draw() override {
			cout << "Drawing a circle with color ";
			m_color.paint();
		}
	};

	class Square : public Shape {	// Concrete Abstraction
		Color& m_color;
	public:
		Square(Color& color) : m_color(color) { }
		void draw() override {
			cout << "Drawing a square with color ";
			m_color.paint();
		}
	};
}