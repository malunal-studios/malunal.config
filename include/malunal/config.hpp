/// @file config.hpp
/// @brief Includes headers which configure a project based on compiler,
///        processor, and platform.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Malunal Studios, LLC.
#ifndef MALUNAL_CONFIG_HPP
#define MALUNAL_CONFIG_HPP
#include <malunal/config/stdafx.hpp>

// Check for compiler config.
#if !defined(MALUNAL_COMPILER_CONFIG)    && \
    !defined(MALUNAL_NO_COMPILER_CONFIG) && \
    !defined(MALUNAL_NO_CONFIG)
#  include <malunal/config/compiler.hpp>
#endif // Compiler config check.
#if defined(MALUNAL_COMPILER_CONFIG)
#  include MALUNAL_COMPILER_CONFIG
#endif // Compiler config inclusion.

// Check for processor config.
#if !defined(MALUNAL_PROCESSOR_CONFIG) && \
    !defined(MALUNAL_NO_PROCESSOR_CONFIG) && \
    !defined(MALUNAL_NO_CONFIG)
#  include <malunal/config/processor.hpp>
#endif // Processor config check.
#if defined(MALUNAL_PROCESSOR_CONFIG)
#  include MALUNAL_PROCESSOR_CONFIG
#endif // Processor config inclusion.

// Check for platform config.
#if !defined(MALUNAL_PLATFORM_CONFIG)    && \
    !defined(MALUNAL_NO_PLATFORM_CONFIG) && \
    !defined(MALUNAL_NO_CONFIG)
#  include <malunal/config/platform.hpp>
#endif // Platform config check.
#if defined(MALUNAL_PLATFORM_CONFIG)
#  include MALUNAL_PLATFORM_CONFIG
#endif // Platform config inclusion.

// Pragma once.
#if MALUNAL_COMPILER_HAS_PRAGMA_ONCE
#  pragma once
#endif // Pragma once check.

#endif // MALUNAL_CONFIG_HPP
