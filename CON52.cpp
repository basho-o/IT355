//CON52-CPP. Prevent data races when accessing bit-fields from multiple threads
//To compile: g++ -pthread CON52.cpp -o ./a.out
#include <iostream>
#include <thread>
#include <mutex>

struct Data {
    unsigned int bitField1 : 1;
    unsigned int bitField2 : 1;
};

std::mutex dataMutex;

void updateBitFields(Data& data) {
    std::lock_guard<std::mutex> lock(dataMutex);

    // Access and modify the bit-fields within the critical section
    data.bitField1 = 1;
    data.bitField2 = 0;
}

int main() {
    Data sharedData;

    std::thread thread1([&sharedData]() {
        updateBitFields(sharedData);
    });

    std::thread thread2([&sharedData]() {
        updateBitFields(sharedData);
    });

    thread1.join();
    thread2.join();

    // Accessing sharedData after synchronization is safe
    std::cout << "bitField1: " << sharedData.bitField1 << ", bitField2: " << sharedData.bitField2 << std::endl;

    return 0;
}
