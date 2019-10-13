libartesky Library Release Notes

RELEASE 1.1.0
Changes:

    added _CROSSLIB directive for switch from MS Windows only lib to cross platform lib
    serial.h header file renamed in libartesky_serial.h
    cross platform lib tested with Arduino on MS Windows 10, Ubuntu 18.04.2 (64 bit)
    based on libartesky v.1.1.0, a version for MS Windows XP has been compiled using MS Visual Studio 2010 32 bit. The library has been modified in order to be conformed with the C++03 standard. Asynchronous connect has been deactivated also if async input parameter has been set.
    connectThreadFunc() function has been modified in order to have, in Linux OS, serial name only has input parameter of connect function compliant with the Artesky Flat Gui application.

Operative System 	32 bit 	64 bit
MS Windows 10 	not tested 	tested
MS Windows 7 	not tested 	tested
MS Windows XP 	tested 	not supported
Linux Ubuntu 19.04 	not supported 	tested
Linux Ubuntu 18.04 	not supported 	tested

RELEASE 1.0.0
Changes:

    first official release
    removed the connect and getSerialPortList functions in the cross-platform refactoring context
    removed the SerialFinder not cross-platform class (serial_finder.h, wserial_finder.cpp)
    build libartesky API-C
    build examples of API-C implementation in C++ and C#
    code cleaning
    documentation updated

BETA RELEASE 0.5.0
Changes:

    new firmware version library management (set in serial.h)
    fast boot management implemented
    synchronous and asynchronous connect option added
    firmware welcome message implemented (active in firmware > 0.1 version only)

BETA RELEASE 0.4.0
Changes:

    remove Arduino delay time in serial port connection
    library tested on MS Windows 64 bit release/debug mode only

BETA RELEASE 0.3.0
Changes:

    modify communication string (from //.//COM in COM)
    added getSerialPort method able to retrieve the flat serial port (if flat is connected)
    library tested on MS Windows 64 bit debug mode only

BETA RELEASE 0.2.0
Changes:

    added SerialFinder class for MS Windows COM port research
    added getSerialPortList method able to retrieve the serial port list
    connect() method implemented for automatic serial port research
    library tested on MS Windows 64 bit debug mode only

BETA RELEASE 0.1.0
Changes:

    First release of the ARTESKY library for Flat Box Generator
    Library tested using UI and Arduino Uno
    Serial port communication based on Windows API
    Microsoft Windows 32/64 bit releases compiled with Microsoft Visual Studio 2017 (v141)
    Windows SDK 10.0.17763.0
