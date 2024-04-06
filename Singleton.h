#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <mutex>
#include <map>
using namespace std;

class Configuration {		// Singleton class
	static Configuration* m_pInstance;
	static std::mutex m_mutex;
	static std::once_flag m_initInstanceFlag;
	Configuration() { cout << "Config instance created." << endl; }
	static void initSingletonInstance() {
		m_pInstance = new Configuration();
	}
	/*void initConfigs() {
		string sLine;
		ifstream readFile("File1.txt");
		while (getline(readFile, sLine)) {
			cout << sLine;
		}
		readFile.close();
	}*/
public:
	Configuration(const Configuration& config) = delete;
	void operator=(const Configuration& config) = delete;
	static Configuration& getInstance();
	void initConfigs() {
		string sLine;
		ifstream readFile("File1.txt");
		while (getline(readFile, sLine)) {
			cout << sLine << endl;
		}
		readFile.close();
	}
};

Configuration* Configuration::m_pInstance{nullptr};
std::mutex Configuration::m_mutex;
std::once_flag Configuration::m_initInstanceFlag;

Configuration& Configuration::getInstance() {
	if (m_pInstance == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_pInstance == nullptr) {
			Configuration* temp = new Configuration();
			m_pInstance = temp;
		}
	}
	// std::call_once(m_initInstanceFlag, &Configuration::initSingletonInstance);
	return *m_pInstance;
}
