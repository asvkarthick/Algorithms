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

    std::cout << "Print elements before reverse" << std::endl;
    for(auto x : v)
        std::cout << x << std::endl;

    reverse(v.begin(), v.end());

    std::cout << "Print elements after reverse" << std::endl;
    for(auto x : v)
        std::cout << x << std::endl;

    auto min_pos = min_element(v.begin(), v.end());
    std::cout << "Min element = " << *min_pos << std::endl;

    auto max_pos = max_element(v.begin(), v.end());
    std::cout << "Max element = "<< *max_pos << std::endl;

    return 0;
}
