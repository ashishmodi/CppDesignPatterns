#pragma once
#include <iostream>
using namespace std;

class Image {
public:
	virtual void display() = 0;
	virtual ~Image() { }
};

class RealImage : public Image {
	string m_sFileName;
public:
	RealImage(const string& sFileName) : m_sFileName(sFileName) {
		cout << "Loading image: " << sFileName << endl;
	}
	void display() override { cout << "Displaying image: " << m_sFileName << endl; }
};

class ImageProxy : public Image {
	RealImage*	m_realImage;
	string		m_sFileName;
public:
	ImageProxy(const string& sFileName) : m_sFileName(sFileName), m_realImage(nullptr) { }
	void display() override {
		if (m_realImage == nullptr) {
			m_realImage = new RealImage(m_sFileName);
		}
		m_realImage->display();
	}
};