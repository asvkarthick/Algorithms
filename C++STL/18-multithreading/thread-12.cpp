#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main() {
    auto fut = std::async([] {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 1000;
     });
    std::cout << "Waiting for the data from the task" << std::endl;
    std::cout << "Received future data : " << fut.get() << std::endl;

    return 0;
}
