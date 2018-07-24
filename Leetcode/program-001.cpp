#include <iostream>
#include <map>
#include <vector>

/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> existing;
        std::vector<int> indices;
        int i;
        
        i = 0;
        
        for(auto value: nums)
        {
            std::map<int,int>::iterator x;
            if((x = existing.find(target - value)) != existing.end())
            {
                indices.push_back(x->second);
                indices.push_back(i);
                return indices;
            }
            existing[value] = i;

            i++;
        }

        return indices;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> v;
    std::vector<int> input { 2, 7, 11, 15 };

    v = s.twoSum(input, 9);

    for(auto value: v)
        std::cout << value << std::endl;

    return 0;
}
