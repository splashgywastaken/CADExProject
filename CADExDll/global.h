#pragma once
// defines
#ifdef CADEXDLL_EXPORTS
#define CADEXDLL_API __declspec(dllexport)
#else
#define CADEXDLL_API __declspec(dllimport)
#endif