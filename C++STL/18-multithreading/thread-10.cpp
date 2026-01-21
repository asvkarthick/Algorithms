#include <iostream>
#include <string>
#include <thread>

thread_local std::string s("This is thread ");

void threadFunction(std::string data) {
    s += data;
    std::cout << "s : " << s << std::endl;
    std::cout << data << " &s : " << &s << std::endl;
}

int main() {
    std::thread t1(threadFunction, "thread1");
    std::thread t2(threadFunction, "thread2");

    t1.join();
    t2.join();

    return 0;
}
