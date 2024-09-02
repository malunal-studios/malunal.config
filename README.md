# Simular.Config

A header only library based on a few sources, such as: Boost.Config and EASTL; for providing mechanisms for configuration of compiler, processor, and platforms for projects including it.

### Motivation

The primary purpose of having this is to solidify macros that are commonly used across modules that we build and to know the capabilities of the target compiler, processor, and platform being compiled for. It provides information on the compiler, processor, and platform currently being compiled for, features of each, and utility macros for portability.

### Usage

There isn't much you can override yourself *in normal usage*, as most of these macros are arbitrated by the library. However, if you need to override something yourself or provide your own configuration there are three macros which you can provide yourself before including this library: `SIMULAR_COMPILER_CONFIG`, `SIMULAR_PROCESSOR_CONFIG`, and `SIMULAR_PLATFORM_CONFIG`. By specifying these yourself, with the value of the header you want to inject into the configuration, you can then include the configuration you want to override. From there you can undefine the problematic macro and redefine it for your purposes. The library does not allow you to redefine these prior to including the file because it arbitrates first.
