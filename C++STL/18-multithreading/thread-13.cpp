#include <iostream>
#include <future>
#include <chrono>
#include <thread>

void threadFunction(std::promise<int>&& p, int a, int b) {
    std::cout << "Thread processing result" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    p.set_value(a * b);
}

int main() {
    std::promise<int> pro;
    std::future<int> fut = pro.get_future();

    std::thread t(threadFunction, std::move(pro), 100, 20);
    std::cout << "Future waiting for result" << std::endl;
    std::cout << "Result = " << fut.get() << std::endl;

    t.join();

    return 0;
}
