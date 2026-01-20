#include <iostream>
#include <thread>

void threadFunction1() {
    std::cout << "threadFunction1 thread ID : " << std::this_thread::get_id() << std::endl;
}

void threadFunction2() {

    std::cout << "threadFunction2 thread ID : " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    std::cout << "t1.get_id() = " << t1.get_id() << std::endl;
    std::cout << "t2.get_id() = " << t2.get_id() << std::endl;
    t1.swap(t2);
    std::cout << "After t1.swap(t2)" << std::endl;
    std::cout << "t1.get_id() = " << t1.get_id() << std::endl;
    std::cout << "t2.get_id() = " << t2.get_id() << std::endl;

    t1.join();
    t2.join();

    return 0;
}
