/// @file windows.hpp
/// @brief Contains the configurations for Windows based platforms.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024-2025 Malunal Studios, LLC.
#include "common.hpp"

// Generic macros.
#define MALUNAL_PLATFORM_UNIX 0
#define MALUNAL_PLATFORM_POSIX 0
#define MALUNAL_PLATFORM_LINUX 0
#define MALUNAL_PLATFORM_WIN32 1
#define MALUNAL_PLATFORM_DESKTOP 1
#define MALUNAL_PLATFORM_NAME "windows"
#define MALUNAL_PLATFORM_DESC \
    MALUNAL_PROCESSOR_NAME "-" MALUNAL_PLATFORM_NAME


// If the compiler doesn't support this, it should define them itself.
// It is valid for these to not have values that they expand to.
#ifndef MALUNAL_SYMBOL_EXPORT
#  define MALUNAL_HAS_DECLSPEC
#  define MALUNAL_SYMBOL_EXPORT __declspec(dllexport)
#  define MALUNAL_SYMBOL_IMPORT __declspec(dllimport)
#endif // MALUNAL_SYMBOL_EXPORT
