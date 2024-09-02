/// @file compiler.hpp
/// @brief Selects a compiler specific header based on defined macros of that
///        compiler, which includes settings for that compiler based on the
///        version of that compiler.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Simular Technologies, LLC.

// TODO(John): Handle other common compilers.
#if defined(__clang__)
#  error Unsupported at this time.
#elif defined(__GNUC__)
#  define SIMULAR_COMPILER_CONFIG "./config/compiler/gcc.hpp"
#elif defined(_MSC_VER)
#  error Unsupported at this time.
#else
#  error Unknown compiler.
#endif // Compiler selection.


// Define helpers here.
#define ST_STRINGIZE(x) #x
#define ST_TOSTRING(x) ST_STRINGIZE(x)
#define ST_PREPROCESSOR_JOIN2(a, b) a##b
#define ST_PREPROCESSOR_JOIN1(a, b) ST_PREPROCESSOR_JOIN2(a, b)
#define ST_PREPROCESSOR_JOIN(a, b) ST_PREPROCESSOR_JOIN1(a, b)
#define ST_UNUSED(x) (void)x
#define ST_EMPTY (void)0
