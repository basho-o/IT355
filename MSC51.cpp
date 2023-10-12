//Rule Code: MSC51-CPP Ensure your random number generator is properly seeded
#include <iostream>
#include <random>

int main() {
    // Seed the random number generator with a value based on the current time
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random number
    std::cout << "Random number: " << gen() << std::endl;

    return 0;
}
