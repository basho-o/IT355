//CTR50-CPP. Guarantee that container indices and iterators are within the valid range
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Check index validity before accessing a container element
    size_t index = 3;
    if (index < vec.size()) {
        std::cout << "Element at index " << index << " is: " << vec[index] << std::endl;
    } else {
        std::cerr << "Index out of range." << std::endl;
    }

    // Using a valid iterator
    auto it = vec.begin() + 2; // Iterator pointing to the third element
    if (it != vec.end()) {
        std::cout << "Third element is: " << *it << std::endl;
    } else {
        std::cerr << "Iterator is invalid." << std::endl;
    }

    return 0;
}
