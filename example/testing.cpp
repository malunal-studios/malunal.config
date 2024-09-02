#include <iostream>
#include <simular/config.hpp>

int
main() {
    std::cout << "Platform " << SIMULAR_PLATFORM_DESC   << std::endl;
    std::cout << "Compiler " << SIMULAR_COMPILER_STRING << std::endl;
}