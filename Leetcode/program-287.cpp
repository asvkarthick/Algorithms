#include <iostream>
#include <vector>

/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2

Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.

*/

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        for(int i = 0; i < n; i++)
        {
            int index = std::abs(nums[i]);
            if(nums[index] < 0)
                return std::abs(nums[i]);
            else
                nums[index] = -nums[index];
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> v1 { 1, 3, 4, 2, 2 };
    std::vector<int> v2 { 3, 1, 3, 4, 2 };

    std::cout << s.findDuplicate(v1) << std::endl;
    std::cout << s.findDuplicate(v2) << std::endl;

    return 0;
}
