cmake_minimum_required(VERSION 3.25)
project(malunal.config.examples VERSION 1.0.0 LANGUAGES CXX)

# Ease of use function.
function(create_example EXAMPLE)
    # Set our required settings.
    set(CMAKE_CXX_STANDARD          23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS        OFF)
    
    set(EXAMPLE_NAME "${PROJECT_NAME}.${EXAMPLE}")
    set(EXAMPLE_FILE "${EXAMPLE}.cpp")
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_FILE})
    target_compile_options(${EXAMPLE_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    target_link_libraries(${EXAMPLE_NAME} PRIVATE malunal::config)
endfunction()

# Create the examples.
create_example(testing)
