cmake_minimum_required(VERSION 3.16)
project(malunal.config VERSION 1.3.0 LANGUAGES CXX)

# Put together library.
add_library(${PROJECT_NAME} INTERFACE)
add_library(malunal::config ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Precompile header.
set(MALCFG_HEADERS ${PROJECT_SOURCE_DIR}/include/malunal/config)
target_precompile_headers(${PROJECT_NAME} INTERFACE ${MALCFG_HEADERS}/stdafx.hpp)
unset(MALCFG_HEADERS)

# Should we build examples?
option(MALUNAL_CONFIG_BUILD_EXAMPLES OFF)
if(MALUNAL_CONFIG_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
