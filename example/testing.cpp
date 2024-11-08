#include <iostream>
#include <malunal/config.hpp>

int
main() {
    std::cout << "Platform " << MALUNAL_PLATFORM_DESC   << std::endl;
    std::cout << "Compiler " << MALUNAL_COMPILER_STRING << std::endl;
}
