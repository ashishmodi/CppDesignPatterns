#pragma once
#include <iostream>
using namespace std;

class DataStorage {
public:
	int m_nData;
};

class USB : DataStorage {
public:
	USB(int num) { m_nData = num; }
	virtual int USB_transmit() {
		std::cout << "Transmitting " << m_nData << " bytes of data from USB device" << endl;
		return m_nData;
	}
};

class SDCard : DataStorage {
public:
	SDCard(int num) { m_nData = num; }
	int SDCard_transmit() {
		std::cout << "Transmitting " << m_nData << " bytes of data from SDCard device" << endl;
		return m_nData;
	}
};

class DataReader {		// Client
public:
	void readDataFromStorage(USB* usbDevice) {
		int nData = usbDevice->USB_transmit();
		cout << "Received data: " << nData << " bytes." << endl;
	}
};

class SDCard_USB_Adapter : public USB {
	SDCard* m_sdCard;
public:
	SDCard_USB_Adapter(SDCard* sdCard) : USB(-1) {
		m_sdCard = sdCard;
	}
	int USB_transmit() override {
		return m_sdCard->SDCard_transmit();
	}
};