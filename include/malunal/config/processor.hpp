/// @file processor.hpp
/// @brief Selects a processor specific header based on defined macros of that
///        processor, which include settings for that processor.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Malunal Studios, LLC.
#if defined(__i386__) || defined(__intel__) || defined(_M_IX86)
#  define MALUNAL_PROCESSOR_CONFIG "./config/processor/x86.hpp"
#elif defined(__x86_64__) || defined(_AMD64_) || defined(_M_AMD64)
#  define MALUNAL_PROCESSOR_CONFIG "./config/processor/x64.hpp"
#else
#  error Unknown processor.
#  error Unknown endianess.
#endif // Processor selection.
