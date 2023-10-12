//ERR54-CPP Catch handlers should order their parameter types from most derived to least derived
#include <iostream>
#include <stdexcept>

class BaseException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Base exception";
    }
};

class DerivedException : public BaseException {
public:
    virtual const char* what() const noexcept override {
        return "Derived exception";
    }
};

int main() {
    try {
        // Some code that may throw exceptions
        throw DerivedException();
    } catch (DerivedException& e) {
        std::cout << "Caught DerivedException: " << e.what() << std::endl;
    } catch (BaseException& e) {
        std::cout << "Caught BaseException: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }

    return 0;
}
