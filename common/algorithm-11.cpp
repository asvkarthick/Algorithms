#include <iostream>
#include <unordered_set>
#include <vector>

/*
    Algorithm:

    Write a function to find if the given sum value can be obtained by adding any two numbers in the input array
    Note that the input array is not sorted array. It will be random array
*/

bool HasPairEqualsSum(const std::vector<int>& data, int sum)
{
    std::unordered_set<int> previous_values;

    for(auto value : data)
    {
        if(previous_values.find(sum - value) != previous_values.end())
            return true;

        previous_values.insert(value);
    }

    return false;
}

int main(void)
{
    std::vector<int> v1 { 4, 1, 2, 3 };
    std::vector<int> v2 { 4, 3, 2, 4 };
    int sum = 8;

    std::cout << HasPairEqualsSum(v1, sum) << std::endl;
    std::cout << HasPairEqualsSum(v2, sum) << std::endl;

    return 0;
}
