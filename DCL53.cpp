//DCL53-CPP. Do not write syntactically ambiguous declarations
#include <iostream>

int main() {
    int a = 10;  // Variable declaration, not ambiguous
    int b(20);   // Variable declaration, not ambiguous

    // Print the values of a and b
    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}
