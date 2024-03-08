#pragma once

#include <iostream>
#include <string>
using namespace std;

class Computer {			// Product class
	string m_sCpu, m_sMemory, m_sStorage;
public:
	void setCpu(const string& sCpu) { m_sCpu = sCpu; }
	void setMemory(const string& sMemory) { m_sMemory = sMemory; }
	void setStorage(const string& sStorage) { m_sStorage = sStorage; }
	void display() { cout << "CPU: " << m_sCpu << ", Memory = " << m_sMemory << ", Storage = " << m_sStorage << endl; }
};

class ComputerBuilder {		// Builder interface
public:
	virtual void buildCpu(const string& sCpu) = 0;
	virtual void buildMemory(const string& sMemory) = 0;
	virtual void buildStorage(const string& sStorage) = 0;
	virtual Computer getComputer() = 0;
};

class DesktopComputerBuilder : public ComputerBuilder {		// Concrete Builder
	Computer m_computer;
public:
	DesktopComputerBuilder() { m_computer = Computer(); }
	void buildCpu(const string& sCpu)			override { m_computer.setCpu(sCpu); }
	void buildMemory(const string& sMemory)		override { m_computer.setMemory(sMemory); }
	void buildStorage(const string& sStorage)	override { m_computer.setStorage(sStorage); }
	Computer getComputer() override { return m_computer; }
};

class LaptopComputerBuilder : public ComputerBuilder {		// Concrete Builder
	Computer m_computer;
public:
	LaptopComputerBuilder() { m_computer = Computer(); }
	void buildCpu(const string& sCpu)			override { m_computer.setCpu(sCpu); }
	void buildMemory(const string& sMemory)		override { m_computer.setMemory(sMemory); }
	void buildStorage(const string& sStorage)	override { m_computer.setStorage("1 TB SSD"); }
	Computer getComputer() override { return m_computer; }
};

class ComputerAssembler {	// Director
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCpu("Intel i7");		// todo: split into Factory
		builder.buildMemory("16 GB");
		builder.buildStorage("512 GB SSD");
		return builder.getComputer();
	}
};