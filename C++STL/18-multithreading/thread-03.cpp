#include <iostream>
#include <string>
#include <thread>

void threadFunctionCopy(std::string s) {
    std::cout << "Executing thread function with copy argument : " << s << std::endl;
}

void threadFunctionReference(const std::string& s) {
    std::cout << "Executing thread function with reference argument : " << s << std::endl;
}

int main() {
    std::string s("Hello World");
    auto lambdaThreadCopy = [=] {
        std::cout << "Executing lambda function copy : " << s << std::endl;
    };
    auto lambdaThreadReference = [&] {
        std::cout << "Executing lambda function reference : " << s << std::endl;
    };

    std::thread thr1(lambdaThreadCopy);
    std::thread thr2(lambdaThreadReference);
    std::thread thr3(threadFunctionCopy, s);
    std::thread thr4(threadFunctionReference, s);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    return 0;
}
