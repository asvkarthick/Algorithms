#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Executing thread function" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread execution completed" << std::endl;
}

int main() {
    std::thread t(threadFunction);
    if (t.joinable()) {
        t.join();
    }
    std::cout << "Main function end" << std::endl;

    return 0;
}
