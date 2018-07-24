#include <iostream>
#include <deque>

// Simple deque program to push and print elements

int main(void)
{
    std::deque<int> dq;
    int i;

    for(i = 0; i < 5; i++)
        dq.push_back(i);

    for(i = 5; i < 10; i++)
        dq.push_front(i);

    std::cout << "Print deque using range based for loop" << std::endl;
    for(auto x : dq)
        std::cout << x << std::endl;

    std::cout << "Print deque using []" << std::endl;
    for(i = 0; i < dq.size(); i++)
        std::cout << dq[i] << std::endl;

    std::cout << "Print deque using iterators" << std::endl;
    for(auto x = dq.begin(); x != dq.end(); x++)
        std::cout << *x << std::endl;

    std::cout << "Print deque using const iterators" << std::endl;
    for(auto x = dq.cbegin(); x != dq.cend(); x++)
        std::cout << *x << std::endl;

    return 0;
}
