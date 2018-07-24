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

    for(auto x : dq)
        std::cout << x << std::endl;

    return 0;
}
