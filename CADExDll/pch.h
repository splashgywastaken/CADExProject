#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

// defines
#ifdef CADEXDLL_EXPORTS
#define CADEXDLL_API __declspec(dllexport)
#else
#define CADEXDLL_API __declspec(dllimport)
#endif

#endif //PCH_H
