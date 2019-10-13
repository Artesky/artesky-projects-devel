#pragma once

#ifndef __SERIALFINDER_H__
#define __SERIALFINDER_H__

#ifndef SERIALFINDER_EXT_CLASS
#define SERIALFINDER_EXT_CLASS
#endif

#include <atlbase.h>
#include <vector>
#include <string>
#include <atlstr.h>
#include <winioctl.h>
#include <setupapi.h>

class SERIALFINDER_EXT_CLASS SerialFinder
{
public:
	typedef std::vector<UINT> PortsArray;
	typedef std::string String;
	typedef std::vector<String> NamesArray;
	typedef std::vector<std::pair<UINT, String> > PortAndNamesArray;

	static _Return_type_success_(return != false) bool findSerialPort(_Inout_ PortsArray& ports);
	bool getComList(std::vector<std::string>& comList);

protected:
	static _Return_type_success_(return != false) bool isNumeric(_In_z_ LPCSTR pszString, _In_ bool bIgnoreColon) noexcept;
	static _Return_type_success_(return != false) bool isNumeric(_In_z_ LPCWSTR pszString, _In_ bool bIgnoreColon) noexcept;
};

#endif