// DCL54-CPP. Overload allocation and deallocation functions as a pair in the same scope
#include <iostream>
#include <cstdlib>

class CustomAllocator {
public:
    static void* operator new(size_t size) {
        std::cout << "CustomAllocator::operator new called\n";
        return std::malloc(size);
    }

    static void operator delete(void* ptr) noexcept {
        std::cout << "CustomAllocator::operator delete called\n";
        std::free(ptr);
    }

    // Other members and methods...
};

int main() {
    CustomAllocator* obj = new CustomAllocator();
    delete obj;
    
    return 0;
}
