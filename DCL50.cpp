//DCL50-CPP. Do not define a C-style variadic function
#include <iostream>
#include <initializer_list>

void print(std::initializer_list<const char*> args) {
    for (const auto& arg : args) {
        std::cout << arg << " ";
    }
}

int main() {
    print({"hello", "world", "!"});
    return 0;
}
