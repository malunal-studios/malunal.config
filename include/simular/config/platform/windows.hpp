/// @file windows.hpp
/// @brief Contains the configurations for Windows based platforms.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Simular Technologies, LLC.
#include "common.hpp"

// Generic macros.
#define SIMULAR_PLATFORM_UNIX 0
#define SIMULAR_PLATFORM_POSIX 0
#define SIMULAR_PLATFORM_LINUX 0
#define SIMULAR_PLATFORM_WIN32 1
#define SIMULAR_PLATFORM_DESKTOP 1
#define SIMULAR_PLATFORM_NAME "windows"
#define SIMULAR_PLATFORM_DESC \
    SIMULAR_PROCESSOR_NAME "-" SIMULAR_PLATFORM_NAME


// If the compiler doesn't support this, it should define them itself.
// It is valid for these to not have values that they expand to.
#ifndef SIMULAR_SYMBOL_EXPORT
#  define SIMLUAR_HAS_DECLSPEC
#  define SIMULAR_SYMBOL_EXPORT __declspec(dllexport)
#  define SIMULAR_SYMBOL_IMPORT __declspec(dllimport)
#endif // SIMULAR_SYMBOL_EXPORT
