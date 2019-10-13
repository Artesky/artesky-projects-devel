#pragma once

#include <string>
#include <vector>

#ifdef _WIN32 
#define ARTESKY_LIB_API extern "C" __declspec(dllimport)
#elif __linux__
#ifdef  ARTESKY_LIB_API
#undef ARTESKY_LIB_API
// Linux export (define ARTESKY_LIB_API in preprocessor options to export)
// Configure C++ option 'Symbols hidden by default' = yes hidden
#define ARTESKY_LIB_API __attribute__((visibility("default")))
#else
// Linux import (DON'T define ARTESKY_LIB_API in preprocessor options to import)
#define ARTESKY_LIB_API
#endif
#endif

typedef uint32_t ASL_ERROR;

//INFO: ARTESKY API Functions
ARTESKY_LIB_API ASL_ERROR flatLoad();
ARTESKY_LIB_API ASL_ERROR flatConnect(const std::string& portName, const bool& async);
ARTESKY_LIB_API ASL_ERROR flatDisconnect();
ARTESKY_LIB_API ASL_ERROR getSerialPort(std::string& serialPort);
ARTESKY_LIB_API ASL_ERROR isFlatConnected(bool& isConnected);
ARTESKY_LIB_API ASL_ERROR turnOn();
ARTESKY_LIB_API ASL_ERROR turnOff();
ARTESKY_LIB_API ASL_ERROR setBrightness(const uint32_t& level);
ARTESKY_LIB_API ASL_ERROR getBrightness(uint32_t& level);
ARTESKY_LIB_API ASL_ERROR getStatus(bool& status);
ARTESKY_LIB_API ASL_ERROR getAPIversion(std::string& version);