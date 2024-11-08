/// @file common.hpp
/// @brief Defines common properties of compiler related configurations.
/// @author John Christman <sorakatadzuma@gmail.com>
/// @copyright 2024 Malunal Studios, LLC.
#if !defined(MALUNAL_CONFIG_HPP)
#  error This file should not be included standalone!
#endif // Inclusion check.

// Redefine the C++11 Version ID.
#ifdef CXX11_VERID
#undef CXX11_VERID
#endif
#define CXX11_VERID 201103L

// Redefine the C++14 Version ID.
#ifdef CXX14_VERID
#undef CXX11_VERID
#endif
#define CXX14_VERID 201402L

// Redefine the C++17 Version ID.
#ifdef CXX17_VERID
#undef CXX17_VERID
#endif
#define CXX17_VERID 201703L

// Redefine the C++20 Version ID.
#ifdef CXX20_VERID
#undef CXX20_VERID
#endif
#define CXX20_VERID 202002L

// Redefine the C++23 Version ID.
#ifdef CXX23_VERID
#undef CXX23_VERID
#endif
#define CXX23_VERID 202302L
