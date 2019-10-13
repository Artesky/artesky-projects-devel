#pragma once

#define NEW_FW_VERSION 0
#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255
#ifdef NEW_FW_VERSION
	#undef ARDUINO_WAIT_TIME
	#define ARDUINO_WAIT_TIME 500
#endif

//MS Windows OS header files
#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>

namespace artesky
{
	class SerialCom
	{
	public:
		SerialCom(const char *portName);
		~SerialCom();

		int readSerialPort(char *buffer, unsigned int buf_size);
		bool writeSerialPort(char *buffer, unsigned int buf_size);
		bool isConnected();

	private:
		#ifdef _WIN32
		HANDLE handler;
		bool connected;
		COMSTAT status;
		DWORD errors;
		#endif
	};
};