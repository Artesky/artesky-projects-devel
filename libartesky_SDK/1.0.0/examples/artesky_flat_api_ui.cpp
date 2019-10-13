#include "libarteskyc.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	ASL_ERROR _ret = 0;					//API return value, 0 = no error
	std::string _version = "";			//API version in major.minor.patch.build format
	std::string _portName = "COM3";		//Port name, for example "COM3"
	bool _async = false;				//Connection behaviour, false = synchronous connection
	bool _isConnected = false;			//Connection check, true = flat box is connected
	uint32_t _level = 100;              //Brightness level, range = [0, 255]
	bool _status = false;				//Lamp status, false = switched off

	std::cout << "libartesky CS wrapper test" << std::endl;
	//DLL starting up
	flatLoad();
	//Get API version
	getAPIversion(_version);
	std::cout << "version: " << _version << std::endl;
	//Open connection with the ARTESKY USB Flat Box
	std::cout << "open connection..." << std::endl;
	_ret = flatConnect(_portName, _async);
	if (_ret == 0)
		std::cout << "connection opened" << std::endl;
	else
		std::cout << "flatConnect: library error" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //Maximum bootloader starting up time
	//Get serial port name
	_portName = "";
	_ret = getSerialPort(_portName);
	if (_ret == 0)
		std::cout << "serial port: " << _portName << std::endl;
	else
		std::cout << "getSerialPort: library error" << std::endl;
	//Check if the ARTESKY USB Flat Box is connected
	_ret = isFlatConnected(_isConnected);
	if (_ret == 0)
	{
		if (_isConnected)
			std::cout << "flat box connected" << std::endl;
		else
			std::cout << "flat box is disconnected" << std::endl;
	}
	else
		std::cout << "isFlatConnected: library error" << std::endl;
	//Switch lamp on
	_ret = turnOn();
	if (_ret == 0)
		std::cout << "Lamp switched on" << std::endl;
	else
		std::cout << "turnOn: library error" << std::endl;
	//Set lamp brightness
	_ret = setBrightness(_level);
	if (_ret == 0)
		std::cout << "Lamp brightness level set to " << _level << std::endl;
	else
		std::cout << "setBrightness: library error" << std::endl;
	//Get lamp brightness
	_level = 0;
	_ret = getBrightness(_level);
	if (_ret == 0)
		std::cout << "brightness level: " << _level << std::endl;
	else
		std::cout << "getBrightness: library error" << std::endl;
	//Get lamp status
	_ret = getStatus(_status);
	if (_ret == 0)
	{
		if (_status)
			std::cout << "lamp On" << std::endl;
		else
			std::cout << "lamp Off" << std::endl;
	}
	else
		std::cout << "getStatus: library error" << std::endl;
	//Switch lamp off
	_ret = turnOff();
	if (_ret == 0)
		std::cout << "Lamp switched off" << std::endl;
	else
		std::cout << "turnOff: library error" << std::endl;
	//Get lamp status
	_ret = getStatus(_status);
	if (_ret == 0)
	{
		if (_status)
			std::cout << "lamp On" << std::endl;
		else
			std::cout << "lamp Off" << std::endl;
	}
	else
		std::cout << "getStatus: library error" << std::endl;
	//Close connection with the ARTESKY USB Flat Box
	_ret = flatDisconnect();
	if (_ret == 0)
		std::cout << "connection closed" << std::endl;
	else
		std::cout << "flatDisconnect: library error" << std::endl;
	std::cout << "Press any key to exit..." << std::endl;
	getchar();
	return EXIT_SUCCESS;
}