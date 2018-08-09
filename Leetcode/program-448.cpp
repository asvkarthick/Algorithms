#include <iostream>
#include <vector>

/*

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        std::vector<int> v;
        
        for(i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }
        
        for(i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                v.push_back(i + 1);
        
        return v;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> v { 4, 3, 2, 7, 8, 3, 1 };

    std::cout << "Input : " << std::endl;
    for(auto elem : v)
        std::cout << elem << " " << std::endl;

    auto out = s.findDisappearedNumbers(v);

    std::cout << "Missing numbers : " << std::endl;
    for(auto elem : out)
        std::cout << elem << " " << std::endl;

    return 0;
}
