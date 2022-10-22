#pragma once

#include <iostream>

#ifdef LEAVERPROGRAM_EXPORTS
#define LEAVERPROGRAM_API __declspec(dllexport)
#else
#define LEAVERPROGRAM_API __declspec(dllimport)
#endif

class Leaver
{
public:
	LEAVERPROGRAM_API std::string leave(std::string name);
};
