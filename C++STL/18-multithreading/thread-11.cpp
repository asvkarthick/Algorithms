#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable condvar;
bool isDataReady = false;

void waiterThread() {
    std::cout << "Waiter thread waiting for data" << std::endl;
    std::unique_lock<std::mutex> lck(mtx);
    condvar.wait(lck, []{ return isDataReady; });
    std::cout << "Received data from notifier" << std::endl;
}

void notifierThread() {
    std::lock_guard<std::mutex> lck(mtx);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    isDataReady = true;
    std::cout << "Notifier thread notifying waiter thread" << std::endl;
    condvar.notify_one();
}

int main() {
    std::thread t1(notifierThread);
    std::thread t2(waiterThread);

    t1.join();
    t2.join();

    return 0;
}
