#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

int count1 = 0;
int count2 = 0;

void threadFunctionWithoutMutex(int n) {
    for (int i = 0; i < n; i++) {
        count1++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

std::mutex m;
void threadFunctionWithMutex(int n) {
    for (int i = 0; i < n; i++) {
        {
            std::lock_guard<std::mutex> mtx(m);
            count2++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::thread t1(threadFunctionWithoutMutex, 1000);
    std::thread t2(threadFunctionWithoutMutex, 1000);
    std::thread t3(threadFunctionWithoutMutex, 1000);

    std::thread t4(threadFunctionWithMutex, 1000);
    std::thread t5(threadFunctionWithMutex, 1000);
    std::thread t6(threadFunctionWithMutex, 1000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout << "count1 = " << count1 << std::endl;
    std::cout << "count2 = " << count2 << std::endl;

    if (count1 != 3000) {
        std::cout << "There was some race in the thread execution in threadFunctionWithoutMutex" << std::endl;
        std::cout << "You might have to use mutex in the critical section" << std::endl;
    }
    if (count2 != 3000) {
        std::cout << "There is some bug in the mutex implementation in threadFunctionWithMutex" << std::endl;
    }

    return 0;
}
