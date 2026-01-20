#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Thread function thread id : " << std::this_thread::get_id() << std::endl;
}

int main(void) {
    std::cout << "Main function thread id : " << std::this_thread::get_id() << std::endl;
    std::cout << "Number of parallel threads : " << std::thread::hardware_concurrency() << std::endl;
    std::thread t(threadFunction);
    std::cout << "t.get_id() = " << t.get_id() << std::endl;
    t.join();

    return 0;
}
