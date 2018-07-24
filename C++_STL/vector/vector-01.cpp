#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 0; i < 10; i++)
        v.push_back(i);

    for(auto x : v)
        std::cout << x << std::endl;

    return 0;
}
