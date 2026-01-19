#include <thread>
#include <iostream>

void threadFunction() {
    std::cout << "Executing thread function" << std::endl;
}

int main() {
    std::thread thr(threadFunction);
    thr.join();

    return 0;
}
