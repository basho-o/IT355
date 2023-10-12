//ERR56-CPP. Guarantee exception safety
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        // Acquire a resource (e.g., allocate memory)
        // This could potentially throw an exception
        resourcePtr = new int[100];
    }

    ~Resource() {
        // Release the acquired resource (e.g., deallocate memory)
        delete[] resourcePtr;
    }

private:
    int* resourcePtr;
};

void performOperation() {
    // Acquire the resource using RAII
    Resource resource;

    // Perform some operation that might throw an exception
    // For demonstration purposes, we'll throw an exception here
    throw std::runtime_error("An error occurred during the operation");
}

int main() {
    try {
        performOperation();
    } catch (const std::exception& e) {
        // Handle the exception appropriately
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // Optionally, log or handle the exception further
    }

    return 0;
}
