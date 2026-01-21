#include <iostream>
#include <thread>
#include <mutex>

std::once_flag onceFlag;
void runOnceThread() {
    std::call_once(onceFlag, [] { std::cout << "Run only once" << std::endl; });
}

int main() {
    std::thread t1(runOnceThread);
    std::thread t2(runOnceThread);

    t1.join();
    t2.join();
}
