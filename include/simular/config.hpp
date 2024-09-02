/// @file config.hpp
/// @brief Includes headers which configure a project based on compiler,
///        processor, and platform.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Simular Technologies, LLC.
#ifndef SIMULAR_CONFIG_HPP
#define SIMULAR_CONFIG_HPP

// Check for compiler config.
#if !defined(SIMULAR_COMPILER_CONFIG)    && \
    !defined(SIMULAR_NO_COMPILER_CONFIG) && \
    !defined(SIMULAR_NO_CONFIG)
#  include <simular/config/compiler.hpp>
#endif // Compiler config check.
#if defined(SIMULAR_COMPILER_CONFIG)
#  include SIMULAR_COMPILER_CONFIG
#endif // Compiler config inclusion.

// Check for processor config.
#if !defined(SIMULAR_PROCESSOR_CONFIG) && \
    !defined(SIMULAR_NO_PROCESSOR_CONFIG) && \
    !defined(SIMULAR_NO_CONFIG)
#  include <simular/config/processor.hpp>
#endif // Processor config check.
#if defined(SIMULAR_PROCESSOR_CONFIG)
#  include SIMULAR_PROCESSOR_CONFIG
#endif // Processor config inclusion.

// Check for platform config.
#if !defined(SIMULAR_PLATFORM_CONFIG)    && \
    !defined(SIMULAR_NO_PLATFORM_CONFIG) && \
    !defined(SIMULAR_NO_CONFIG)
#  include <simular/config/platform.hpp>
#endif // Platform config check.
#if defined(SIMULAR_PLATFORM_CONFIG)
#  include SIMULAR_PLATFORM_CONFIG
#endif // Platform config inclusion.

// Pragma once.
#if SIMULAR_COMPILER_HAS_PRAGMA_ONCE
#  pragma once
#endif // Pragma once check.

#endif // SIMULAR_CONFIG_HPP
