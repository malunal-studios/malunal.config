cmake_minimum_required(VERSION 3.16)
project(malunal.config VERSION 1.2.0 LANGUAGES CXX)

set(MALUNAL_CONFIG_TOP_LEVEL OFF)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(MALUNAL_CONFIG_TOP_LEVEL ON)
endif()

include(FetchContent)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} INTERFACE)
add_library(malunal::config ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Precompile header.
set(MALUNAL_CONFIG_HEADERS ${PROJECT_SOURCE_DIR}/include/malunal/config)
target_precompile_headers(${PROJECT_NAME} INTERFACE ${MALUNAL_CONFIG_HEADERS}/stdafx.hpp)
unset(MALUNAL_CONFIG_HEADERS)


# In house builds.
if(MALUNAL_CONFIG_TOP_LEVEL)
    target_compile_options(
        ${PROJECT_NAME}
        INTERFACE -Wall
        INTERFACE -Wextra
        INTERFACE -Wpedantic
    )
endif()

# Build example?
option(MALUNAL_CONFIG_BUILD_EXAMPLE "Build example" OFF)
if(MALUNAL_CONFIG_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
