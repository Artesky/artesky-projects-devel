#pragma once
#ifdef _WIN32
#pragma warning(disable: 4251)
#endif

#ifdef _WIN32
#include "libartesky_info.h"
#endif

#include "serial.h"
#include "serial_finder.h"
#include "libartesky_defs.h"
#include "libartesky_errors.h"
#include <string>
#include <atomic>

namespace artesky
{
	class FLAT_API Flat
	{
	public:
		Flat();
		virtual ~Flat();
	public:
		ASL_ERROR connect(const char *portName, const bool& async = true);
		ASL_ERROR connect();
		ASL_ERROR disconnect();
		ASL_ERROR getSerialPortList(std::vector<std::string>& portList);
		ASL_ERROR getSerialPort(std::string& serialPort);
		ASL_ERROR isFlatConnected(bool& isConnected);
		ASL_ERROR turnOn();
		ASL_ERROR turnOff();
		ASL_ERROR setBrightness(const uint32_t& level);
		ASL_ERROR getBrightness(uint32_t& level);
		ASL_ERROR getStatus(bool& status);
		ASL_ERROR getAPIversion(std::string& version);
	private:
		void connectThreadFunc(const char *portName);
		bool isConnectionOpen();
		bool readWelcome();
		ASL_ERROR sendCommand(const std::string& cmd, std::string& reply);
	private:
		SerialCom*			   m_serial{ nullptr };
		SerialFinder*		   m_serialFinder{ nullptr };
		std::atomic<bool>	   m_isConnected{ false };
		std::atomic<bool>	   m_isLampOn{ false };
		std::string			   m_serialPort{ "" };
	};
}