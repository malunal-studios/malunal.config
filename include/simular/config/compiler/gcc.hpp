/// @file gcc.hpp
/// @brief Defines configurations for the compiler being used.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Simular Technologies, LLC.
#include "common.hpp"

// Define a comprehensible and consistent compiler version.
#define SIMULAR_GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

// Generic macros.
#define SIMULAR_COMPILER_CLANG   0
#define SIMULAR_COMPILER_GCC     1
#define SIMULAR_COMPILER_MSVC    0
#define SIMULAR_COMPILER_NAME    "GCC"
#define SIMULAR_COMPILER_VERSION SIMULAR_GCC_VERSION
#define SIMULAR_COMPILER_STRING     \
    SIMULAR_COMPILER_NAME       " " \
    ST_TOSTRING(__GNUC__)       "." \
    ST_TOSTRING(__GNUC_MINOR__) "." \
    ST_TOSTRING(__GNUC_PATCHLEVEL__)


// Makes a version for this compiler, used for comparsions.
#define SIMULAR_COMPILER_MAKE_VERSION(major, minor, patch) \
    (major * 1000 + minor * 100 + patch)


// Has feature and has builtin support.
// GCC does not have has feature.
#define SIMULAR_COMPILER_HAS_PRAGMA_ONCE 1
#define SIMULAR_COMPILER_NO_HAS_FEATURE 1
#define SIMULAR_COMPILER_NO_HAS_BUILTIN 0
#define SIMULAR_COMPILER_HAS_FEATURE(x)
#define SIMULAR_COMPILER_HAS_BUILTIN(x) __has_builtin(x)


// C++17 check, lowest supported version.
#if __cplusplus >= CXX17_VERID
#  define SIMULAR_CXX11 1
#  define SIMULAR_CXX14 1
#  define SIMULAR_CXX17 1
#else // Not supported.
#  if SIMULAR_GCC_VERSION >= SIMULAR_COMPILER_MAKE_VERSION(8,0,0)
#    error GCC8.0 compiler with no C++17 support!
#  else // Normal case.
#    error Your compiler must support C++17 minimum.
#  endif // GCC version check.
#endif // C++17 check.

// C++20 check.
#if __cplusplus >= CXX20_VERID
#  define SIMULAR_CXX20 1
#else
#  define SIMULAR_CXX20 0
#endif // C++20 check.

// C++23 check.
#if __cplusplus >= CXX23_VERID
#  define SIMULAR_CXX23 1
#else
#  define SIMULAR_CXX23 0
#endif // C++23 check.


// C++20 checks.
#if SIMULAR_CXX20
#  define SIMULAR_COMPILER_NO_DESIGNATED_INITIALIZERS 0
#else // Not supported.
#  define SIMULAR_COMPILER_NO_DESIGNATED_INITIALIZERS 1
#endif // SIMULAR_CXX20


// Define well supported macros.
#define ST_FORCE_INLINE    inline __attribute__((always_inline))
#define ST_NO_INLINE       __attribute__((noinline))
#define ST_PURE            __attribute__((pure))
#define ST_WEAK            __attribute__((weak))
#define ST_MAY_ALIAS       __attribute__((__may_alias__))
#define ST_DEPRECATED(msg) __attribute__((deprecated(msg)))
#define ST_UNREACHABLE     __builtin_unreachable()

#define ST_PACKED                __attribute__((packed))
#define ST_ALIGN(n)              __attribute__((aligned(n)))
#define ST_ALIGNOF(type)         ((size_t)__alignof__(type))
#define ST_ALIGNED(type, var, n) type var ST_ALIGN(n)

#define ST_LIKELY(x)   __builtin_expect(!!(x), true)
#define ST_UNLIKELY(x) __builtin_expect(!!(x), false)


// Set up warning disablers.
#define SIMULAR_GCCW_HELP2(x) #x
#define SIMULAR_GCCW_HELP1(x) SIMULAR_GCCW_HELP2(GCC diagnostic ignored x)
#define SIMULAR_GCCW_HELP0(x) SIMULAR_GCCW_HELP1(#x)
#if SIMULAR_GCC_VERSION > SIMULAR_COMPILER_MAKE_VERSION(4,0,6)
#  define ST_GCCD_DISABLE(w)         \
      _Pragma("GCC diagnostic push") \
      _Pragma(SIMULAR_GCCW_HELP0(w))
#elif SIMULAR_GCC_VERSION > SIMULAR_COMPILER_MAKE_VERSION(4,0,4)
#  define ST_GCCD_DISABLE(w) \
      _Pragma(SIMULAR_GCCW_HELP0(w))
#else // Not supported.
#  define ST_GCCD_DISABLE(w)
#endif // GCC version check for diagnostic push.


// Set up warning restorers.
#if SIMULAR_GCC_VERSION > SIMULAR_COMPILER_MAKE_VERSION(4,0,6)
#  define ST_GCCD_RESTORE() \
      _Pragma("GCC diagnostic pop")
#else // Not supported.
#  define ST_GCCD_RESTORE()
#endif // GCC version check for diagnostic pop.


// Set up warning as error.
#define SIMULAR_GCCE_HELP2(x) #x
#define SIMULAR_GCCE_HELP1(x) SIMULAR_GCCE_HELP2(GCC diagnostic error x)
#define SIMULAR_GCCE_HELP0(x) SIMULAR_GCCE_HELP1(#x)
#if SIMULAR_GCC_VERSION > SIMULAR_COMPILER_MAKE_VERSION(4,0,6)
#  define ST_GCCD_ERROR(e)           \
      _Pragma("GCC diagnostic push") \
      _Pragma(SIMULAR_GCCE_HELP0(e))
#elif SIMULAR_GCC_VERSION > SIMULAR_COMPILER_MAKE_VERSION(4,0,4)
#  define ST_GCCD_ERROR(e) \
      _Pragma(SIMULAR_GCCE_HELP0(e))
#else // Not supported.
#  define ST_GCCD_ERROR(e)
#endif // GCC version check for diagnostic error.


// Optimization switches.
#define ST_OPTIMIZE_OFF()  \
    _Pragma("GCC push_options") \
    _Pragma("GCC optimize 0")

#define ST_OPTIMIZE_ON() \
    _Pragma("GCC pop_options")


// Bad compiler version.
#if SIMULAR_GCC_VERSION < SIMULAR_COMPILER_MAKE_VERSION(8,0,0)
#  error Compiler not configured - please reconfigure.
#endif // GCC version check for bad compiler.
