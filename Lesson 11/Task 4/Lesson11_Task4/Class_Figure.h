#pragma once

#include <iostream>

#ifdef FIGURE_DLL_EXPORTS
#define FIGURE_DLL_API __declspec(dllexport)
#else
#define FIGURE_DLL_API __declspec(dllimport)
#endif

class Figure
{
protected:
    std::string name;
    FIGURE_DLL_API Figure(std::string name);
public:
    FIGURE_DLL_API Figure();
    FIGURE_DLL_API virtual void print() const;
};