//ERR59-CPP: Do not throw an exception across execution boundaries
#include <iostream>
#include <stdexcept>

void someFunction() {
    try {
        // Code that may throw an exception
        throw std::runtime_error("An error occurred");
    } catch (const std::exception& e) {
        // Handle the exception within the same execution boundary
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // Optionally log or handle the exception further
    }
}

int main() {
    someFunction(); // Call a function that might throw an exception

    return 0;
}
