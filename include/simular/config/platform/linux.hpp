/// @file linux.hpp
/// @brief Contains the configurations for linux based platforms.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Simular Technologies, LLC.
#include "common.hpp"

// Generic macros.
#define SIMULAR_PLATFORM_UNIX 1
#define SIMULAR_PLATFORM_POSIX 1
#define SIMULAR_PLATFORM_LINUX 1
#define SIMULAR_PLATFORM_WIN32 0
#define SIMULAR_PLATFORM_DESKTOP 1
#define SIMULAR_PLATFORM_NAME "linux"
#define SIMULAR_PLATFORM_DESC \
    SIMULAR_PROCESSOR_NAME "-" SIMULAR_PLATFORM_NAME


// if the compiler is not gcc we still need to be able to parse
// the GNU system headers, some of which (mainly <stdint.h>)
// use GNU specific extensions:
#ifndef __GNUC__
#  ifndef __extension__
#     define __extension__
#  endif
#  ifndef __const__
#     define __const__ const
#  endif
#  ifndef __volatile__
#     define __volatile__ volatile
#  endif
#  ifndef __signed__
#     define __signed__ signed
#  endif
#  ifndef __typeof__
#     define __typeof__ typeof
#  endif
#  ifndef __inline__
#     define __inline__ inline
#  endif
#endif
