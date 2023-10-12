//ERR55-CPP. Honor exception specifications
#include <iostream>
#include <stdexcept>

// Function with a specific exception specification
void myFunction() noexcept(false) {
    // This function might throw exceptions that are not std::exception
    throw std::runtime_error("An error occurred");
}

int main() {
    try {
        myFunction(); // Call the function that might throw an exception
    } catch (const std::exception& e) {
        // Handle the exception appropriately
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // Optionally, log or handle the exception further
    }

    return 0;
}
