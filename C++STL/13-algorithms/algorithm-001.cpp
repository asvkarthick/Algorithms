#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 10; i > 0; --i)
        v.push_back(i);

    std::vector<int>::iterator pos1 = find(v.begin(), v.end(), 3);
    std::cout << *pos1 << std::endl;

    auto pos2 = find(v.begin(), v.end(), 5);
    std::cout << *pos2 << std::endl;

    pos2 = find(pos2, v.end(), 2);
    std::cout << *pos2 << std::endl;

    return 0;
}
