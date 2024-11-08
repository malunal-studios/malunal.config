/// @file gcc.hpp
/// @brief Defines configurations for the compiler being used.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Malunal Studios, LLC.
#include "common.hpp"

// Define a comprehensible and consistent compiler version.
#define MALUNAL_GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

// Generic macros.
#define MALUNAL_COMPILER_CLANG   0
#define MALUNAL_COMPILER_GCC     1
#define MALUNAL_COMPILER_MSVC    0
#define MALUNAL_COMPILER_NAME    "GCC"
#define MALUNAL_COMPILER_VERSION MALUNAL_GCC_VERSION
#define MALUNAL_COMPILER_STRING     \
    MALUNAL_COMPILER_NAME       " " \
    MAL_TOSTRING(__GNUC__)       "." \
    MAL_TOSTRING(__GNUC_MINOR__) "." \
    MAL_TOSTRING(__GNUC_PATCHLEVEL__)


// Makes a version for this compiler, used for comparsions.
#define MALUNAL_COMPILER_MAKE_VERSION(major, minor, patch) \
    (major * 1000 + minor * 100 + patch)


// Has feature and has builtin support.
// GCC does not have has feature.
#define MALUNAL_COMPILER_HAS_PRAGMA_ONCE 1
#define MALUNAL_COMPILER_NO_HAS_FEATURE 1
#define MALUNAL_COMPILER_NO_HAS_BUILTIN 0
#define MALUNAL_COMPILER_HAS_FEATURE(x)
#define MALUNAL_COMPILER_HAS_BUILTIN(x) __has_builtin(x)


// C++17 check, lowest supported version.
#if __cplusplus >= CXX17_VERID
#  define MALUNAL_CXX11 1
#  define MALUNAL_CXX14 1
#  define MALUNAL_CXX17 1
#else // Not supported.
#  if MALUNAL_GCC_VERSION >= MALUNAL_COMPILER_MAKE_VERSION(8,0,0)
#    error GCC8.0 compiler with no C++17 support!
#  else // Normal case.
#    error Your compiler must support C++17 minimum.
#  endif // GCC version check.
#endif // C++17 check.

// C++20 check.
#if __cplusplus >= CXX20_VERID
#  define MALUNAL_CXX20 1
#else
#  define MALUNAL_CXX20 0
#endif // C++20 check.

// C++23 check.
#if __cplusplus >= CXX23_VERID
#  define MALUNAL_CXX23 1
#else
#  define MALUNAL_CXX23 0
#endif // C++23 check.


// C++20 checks.
#if MALUNAL_CXX20
#  define MALUNAL_COMPILER_NO_DESIGNATED_INITIALIZERS 0
#else // Not supported.
#  define MALUNAL_COMPILER_NO_DESIGNATED_INITIALIZERS 1
#endif // MALUNAL_CXX20


// Define well supported macros.
#define MAL_FORCE_INLINE    inline __attribute__((always_inline))
#define MAL_NO_INLINE       __attribute__((noinline))
#define MAL_PURE            __attribute__((pure))
#define MAL_WEAK            __attribute__((weak))
#define MAL_MAY_ALIAS       __attribute__((__may_alias__))
#define MAL_DEPRECATED(msg) __attribute__((deprecated(msg)))
#define MAL_UNREACHABLE     __builtin_unreachable()

#define MAL_PACKED                __attribute__((packed))
#define MAL_ALIGN(n)              __attribute__((aligned(n)))
#define MAL_ALIGNOF(type)         ((size_t)__alignof__(type))
#define MAL_ALIGNED(type, var, n) type var MAL_ALIGN(n)

#define MAL_LIKELY(x)   __builtin_expect(!!(x), true)
#define MAL_UNLIKELY(x) __builtin_expect(!!(x), false)


// Set up warning disablers.
#define MALUNAL_GCCW_HELP2(x) #x
#define MALUNAL_GCCW_HELP1(x) MALUNAL_GCCW_HELP2(GCC diagnostic ignored x)
#define MALUNAL_GCCW_HELP0(x) MALUNAL_GCCW_HELP1(#x)
#if MALUNAL_GCC_VERSION > MALUNAL_COMPILER_MAKE_VERSION(4,0,6)
#  define MAL_GCCD_DISABLE(w)         \
      _Pragma("GCC diagnostic push") \
      _Pragma(MALUNAL_GCCW_HELP0(w))
#elif MALUNAL_GCC_VERSION > MALUNAL_COMPILER_MAKE_VERSION(4,0,4)
#  define MAL_GCCD_DISABLE(w) \
      _Pragma(MALUNAL_GCCW_HELP0(w))
#else // Not supported.
#  define MAL_GCCD_DISABLE(w)
#endif // GCC version check for diagnostic push.


// Set up warning restorers.
#if MALUNAL_GCC_VERSION > MALUNAL_COMPILER_MAKE_VERSION(4,0,6)
#  define MAL_GCCD_RESTORE() \
      _Pragma("GCC diagnostic pop")
#else // Not supported.
#  define MAL_GCCD_RESTORE()
#endif // GCC version check for diagnostic pop.


// Set up warning as error.
#define MALUNAL_GCCE_HELP2(x) #x
#define MALUNAL_GCCE_HELP1(x) MALUNAL_GCCE_HELP2(GCC diagnostic error x)
#define MALUNAL_GCCE_HELP0(x) MALUNAL_GCCE_HELP1(#x)
#if MALUNAL_GCC_VERSION > MALUNAL_COMPILER_MAKE_VERSION(4,0,6)
#  define MAL_GCCD_ERROR(e)           \
      _Pragma("GCC diagnostic push") \
      _Pragma(MALUNAL_GCCE_HELP0(e))
#elif MALUNAL_GCC_VERSION > MALUNAL_COMPILER_MAKE_VERSION(4,0,4)
#  define MAL_GCCD_ERROR(e) \
      _Pragma(MALUNAL_GCCE_HELP0(e))
#else // Not supported.
#  define MAL_GCCD_ERROR(e)
#endif // GCC version check for diagnostic error.


// Optimization switches.
#define MAL_OPTIMIZE_OFF()  \
    _Pragma("GCC push_options") \
    _Pragma("GCC optimize 0")

#define MAL_OPTIMIZE_ON() \
    _Pragma("GCC pop_options")


// Bad compiler version.
#if MALUNAL_GCC_VERSION < MALUNAL_COMPILER_MAKE_VERSION(8,0,0)
#  error Compiler not configured - please reconfigure.
#endif // GCC version check for bad compiler.
