#include <iostream>
#include <vector>

/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> v;
        int i;
        
        for(i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
                v.push_back(abs(nums[i]));
            nums[index] = -nums[index];
        }
        
        return v;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> v { 4, 3, 2, 7, 8, 2, 3, 1 };
    auto out = s.findDuplicates(v);

    for(auto elem : out)
        std::cout << elem << std::endl;

    return 0;
}
