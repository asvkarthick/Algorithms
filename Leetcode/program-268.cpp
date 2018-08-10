#include <iostream>
#include <vector>

/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        
        int total = (n * (n + 1)) / 2;
        for(auto num : nums)
            total -= num;
        
        return total;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> v1 {3, 0, 1};
    std::vector<int> v2{9, 6, 4, 2, 3, 5, 7, 0, 1};

    std::cout << s.missingNumber(v1) << std::endl;
    std::cout << s.missingNumber(v2) << std::endl;

    return 0;
}
