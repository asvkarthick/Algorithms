#include <iostream>
#include <vector>

/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> nums;
        auto x = nums1.begin();
        auto y = nums2.begin();

        while(x != nums1.end() && y != nums2.end())
        {
            if(*x <= *y)
            {
                nums.push_back(*x);
                x++;
            }
            else
            {
                nums.push_back(*y);
                y++;
            }
        }
        while(x != nums1.end())
        {
            nums.push_back(*x);
            x++;
        }
        while(y != nums2.end())
        {
            nums.push_back(*y);
            y++;
        }

        if(nums.size() & 1)
            return static_cast<double>(nums[nums.size() >> 1]);
        else
            return (static_cast<double>(nums[nums.size() / 2]) + static_cast<double>(nums[nums.size() / 2 - 1])) / 2.0;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> nums1 { 1, 2 };
    std::vector<int> nums2 { 3, 4 };

    std::cout << s.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
