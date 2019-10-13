#pragma once

#ifdef _WIN32
// Microsoft Windows OS
#ifdef API_EXPORTS
#define FLAT_API __declspec(dllexport)
#else
#define FLAT_API __declspec(dllimport)
#endif
#else
// GNU Linux OS
#define FLAT_API
#endif