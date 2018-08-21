#include <iostream>
#include <vector>
#include <limits.h>

// Algorithm to find the second max
int secondMax(std::vector<int>& v)
{
    int max, second_max;
    if(v.size() <= 2)
        return 0;

    max = v[0];
    second_max = v[1];

    if(second_max > max)
    {
        int tmp = second_max;
        second_max = max;
        max = tmp;
    }

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > max)
        {
            second_max = max;
            max = v[i];
        }
        else if(v[i] > second_max && v[i] < max)
        {
            second_max = max;
        }
    }

    return second_max;
}

int main(void)
{
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int> v2 {5, 4, 3, 2, 1};

    std::cout << "Second max of v1 = " << secondMax(v1) << std::endl;
    std::cout << "Second max of v2 = " << secondMax(v2) << std::endl;

    return 0;
}
