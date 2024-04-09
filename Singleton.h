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
	static map<string, string> m_mapConfigs;

	Configuration() { cout << "Config instance created." << endl; }

	static void initSingletonInstance() {
		m_pInstance = new Configuration();
	}
public:
	Configuration(const Configuration& config) = delete;
	void operator=(const Configuration& config) = delete;
	static Configuration& getInstance();

	static bool loadConfigs() {
		ifstream readFile("File1.txt");
		if (readFile.fail()) {
			cout << "File open failed" << endl;
			return false;
		}

		string sLine;
		string sDelimeter = ":";
		size_t position = 0;
		try {
			while (getline(readFile, sLine)) {		// day:Monday
				/*while ((position = sLine.find(sDelimeter)) != std::string::npos) {	// scott:tiger:mushroom
					string sData = sLine.substr(0, position);		// scott
					sLine.erase(0, position + sDelimeter.length());	// tiger:mushroom - delete everything before delimeter
				}*/
				if ((position = sLine.find(sDelimeter)) != std::string::npos) {		// pos = 3
					string sKey = sLine.substr(0, position);						// day
					string sValue = sLine.substr(position + 1, sLine.length());		// Monday
					m_mapConfigs.insert(make_pair(sKey, sValue));
				}
			}
			readFile.close();
		}
		catch (const std::exception& ex) {
			cerr << "Got exception: " << ex.what() << endl;
			return false;
		}
		cout << "* Printing configs *" << endl;
		map<string, string>::iterator iter = m_mapConfigs.begin();
		while (iter != m_mapConfigs.end()) {
			cout << iter->first << " :: " << iter->second << endl;
			++iter;
		}
		return true;
	}

	static string getValue(string sKey) {
		if (m_mapConfigs.contains(sKey))
			return m_mapConfigs[sKey];
		throw sKey + " key not found";
	}
};

Configuration* Configuration::m_pInstance{nullptr};
std::mutex Configuration::m_mutex;
std::once_flag Configuration::m_initInstanceFlag;
map<string, string> Configuration::m_mapConfigs;

Configuration& Configuration::getInstance() {
	if (m_pInstance == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_pInstance == nullptr) {
			if (loadConfigs()) {
				Configuration* temp = new Configuration();
				m_pInstance = temp;
			}
			else
				throw "Unable to create configuration object as load config failed";
		}
	}
	// std::call_once(m_initInstanceFlag, &Configuration::initSingletonInstance);
	return *m_pInstance;
}
