#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class ScreenType { Normal, Touchscreen };
constexpr const char* ScreenTypeToString(ScreenType st) noexcept(false) {
	switch (st) {
		case ScreenType::Normal:		return "Normal";
		case ScreenType::Touchscreen:	return "TouchScreen";
		default:	throw std::invalid_argument("String not found for this type");
	}
}

class Computer {			// Product class
	string m_sCpu, m_sMemory, m_sStorage;
public:
	vector<ScreenType> m_vScreenType;
	void setCpu(const string& sCpu) { m_sCpu = sCpu; }
	void setMemory(const string& sMemory) { m_sMemory = sMemory; }
	void setStorage(const string& sStorage) { m_sStorage = sStorage; }
	void displayScreenType() {
		cout << "Screen types supported are: " << endl;
		for (ScreenType screen : m_vScreenType) { cout << ScreenTypeToString(screen) << endl; }
	}
	void display() { cout << "CPU: " << m_sCpu << ", Memory = " << m_sMemory << ", Storage = " << m_sStorage << endl; displayScreenType(); }
};

class ComputerBuilder {		// Builder interface
public:
	Computer m_computer;
	virtual ComputerBuilder& buildCpu(const string& sCpu) = 0;
	virtual ComputerBuilder& buildMemory(const string& sMemory) = 0;
	virtual ComputerBuilder& buildStorage(const string& sStorage) = 0;
	virtual ComputerBuilder& buildScreen(ScreenType screenType) = 0;
	void addScreenType(ScreenType screenType) { m_computer.m_vScreenType.push_back(screenType); }
	virtual Computer getComputer() { return m_computer; }			// Can be done in child class
};

class DesktopComputerBuilder : public ComputerBuilder {		// Concrete Builder
public:
	DesktopComputerBuilder() { m_computer = Computer(); }
	ComputerBuilder& buildCpu(const string& sCpu)			override { m_computer.setCpu(sCpu);			return *this; }
	ComputerBuilder& buildMemory(const string& sMemory)		override { m_computer.setMemory(sMemory);	return *this; }
	ComputerBuilder& buildStorage(const string& sStorage)	override { m_computer.setStorage(sStorage);	return *this; }
	ComputerBuilder& buildScreen(ScreenType screenType)		override { this->addScreenType(screenType); return *this; }
};

class LaptopComputerBuilder : public ComputerBuilder {		// Concrete Builder
public:
	LaptopComputerBuilder() { m_computer = Computer(); }
	ComputerBuilder& buildCpu(const string& sCpu)			override { m_computer.setCpu(sCpu);			return *this; }
	ComputerBuilder& buildMemory(const string& sMemory)		override { m_computer.setMemory(sMemory);	return *this; }
	ComputerBuilder& buildStorage(const string& sStorage)	override { m_computer.setStorage(sStorage); return *this; }
	ComputerBuilder& buildScreen(ScreenType screenType)		override { this->addScreenType(screenType); return *this; }
};

class ComputerAssembler {	// Director
	ComputerBuilder* m_computerBuilder;
public:
	void setBuilderType(ComputerBuilder* builder) { this->m_computerBuilder = builder; }

	Computer assembleComputer() {
		m_computerBuilder->buildCpu("Intel i5").buildMemory("16 GB").buildStorage("512 GB SSD").buildScreen(ScreenType::Normal);		// todo: split into Factory
		return m_computerBuilder->getComputer();
	}

	Computer assembleLaptop() {
		m_computerBuilder->buildCpu("Intel i7").buildMemory("16 GB").buildStorage("1TB SSD").buildScreen(ScreenType::Normal).buildScreen(ScreenType::Touchscreen);
		return m_computerBuilder->getComputer();
	}
};