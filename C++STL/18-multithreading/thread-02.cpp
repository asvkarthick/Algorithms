#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Executing thread function" << std::endl;
}

class ThreadClass {
public:
    void operator()() {
        std::cout << "Executing thread object" << std::endl;
    }
};

int main() {
    auto threadLambda = []() {
        std::cout << "Executing thread lambda" << std::endl;
    };
    std::thread thr1(threadFunction);
    ThreadClass threadClassObject;
    std::thread thr2(threadClassObject);
    std::thread thr3(threadLambda);

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
