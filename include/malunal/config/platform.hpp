/// @file platform.hpp
/// @brief Selects a platform specific header based on defined macros of that
///        platform, which includes settings for that platform.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024-2025 Malunal Studios, LLC.
#if defined(linux)     || \
    defined(__linux)   || \
    defined(__linux__) || \
    defined(__GNU__)   || \
    defined(__GLIBC__)
#  define MALUNAL_PLATFORM_CONFIG "./config/platform/linux.hpp"
#elif defined(WIN32)     || \
      defined(_WIN32)    || \
      defined(__WIN32__)
#  define MALUNAL_PLATFORM_CONFIG "./config/platform/windows.hpp"
#else
#  error Unknown platform.
#endif // Platform selection.
