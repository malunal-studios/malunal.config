# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.3.0] - 2025-04-07

### Changed

- Updated copyright date to `2024-2025`.
- Updated compiler requirements to support C++ `>=23`.
- Updated `build.py` to utilize `Ninja` generator instead of `Unix Makefiles`.
  - Slight build time improvement seen as a result since Ninja is simpler to execute overall.
- Moved the only current example to `examples`.
- Renamed example executable name.
- Changed implementation of `string_t` alias to `std::pmr::string` from `std::string`.

### Added

- Added CMake function for creating an example.
- Added various missed includes for `stdafx.hpp`.
- Added various extra alias, such as `stack_t`.

## [1.2.0] - 2024-11-15

### Changed

- Library assumes C++23 now, and enforces it.
  - Needed for specific features, namely `std::expected`.

### Added

- Precompiled header to speed up compilation times since many of the standard library headers are imported.
- Custom typedefs for commonly used collections, structures, etc.

## [1.1.0] - 2024-11-08

### Changed

- Company rebranding, changed any instance of the terms `Simular` to `Malunal` and `Simular Technologies, LLC` to `Malunal Studios, LLC`

## [1.0.0] - 2024-09-02

### Added
- Support for C++ `>=17`.
- Support for GCC `>=8.0`.
- Detection and bare-bones support for Windows
- Detection and bare-bones support for Linux
- Detection and bare-bones support for x86
- Detection and bare-bones support for x64
