/* Problem: Find peak element
 * Weblink: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/3032/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int findPeak(std::vector<int>& nums, int start, int end)
    {
        if (start == end) return start;
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid + 1])
            return findPeak(nums, start, mid);
        return findPeak(nums, mid + 1, end);
    }

    int findPeakElement(vector<int>& nums) {
        return findPeak(nums, 0, nums.size() - 1);
    }
};
