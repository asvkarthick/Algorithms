#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 10; i < 50; i++)
        v.push_back(i);

    auto pos20 = find(v.begin(), v.end(), 20);
    auto pos30 = find(v.begin(), v.end(), 30);
    auto max_pos = max_element(pos20, pos30);
    auto min_pos = min_element(pos20, pos30);
    std::cout << "Min between 20 and 30 is " << *min_pos << std::endl;
    std::cout << "Max between 20 and 30 is " << *max_pos << std::endl;

    //  Half open range so we need to give a pointer behind the last element
    max_pos = max_element(pos20, ++pos30);
    std::cout << "Max between 20 and 30 is " << *max_pos << std::endl;

    return 0;
}
