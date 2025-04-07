/// @file compiler.hpp
/// @brief Selects a compiler specific header based on defined macros of that
///        compiler, which includes settings for that compiler based on the
///        version of that compiler.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024-2025 Malunal Studios, LLC.

// TODO(John): Handle other common compilers.
#if defined(__clang__)
#  error Unsupported at this time.
#elif defined(__GNUC__)
#  define MALUNAL_COMPILER_CONFIG "./config/compiler/gcc.hpp"
#elif defined(_MSC_VER)
#  error Unsupported at this time.
#else
#  error Unknown compiler.
#endif // Compiler selection.


// Define helpers here.
#define MAL_STRINGIZE(x) #x
#define MAL_TOSTRING(x) MAL_STRINGIZE(x)
#define MAL_PREPROCESSOR_JOIN2(a, b) a##b
#define MAL_PREPROCESSOR_JOIN1(a, b) MAL_PREPROCESSOR_JOIN2(a, b)
#define MAL_PREPROCESSOR_JOIN(a, b) MAL_PREPROCESSOR_JOIN1(a, b)
#define MAL_UNUSED(x) (void)x
#define MAL_EMPTY (void)0
