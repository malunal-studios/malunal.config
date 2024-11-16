# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
