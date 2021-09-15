/* Program: Binary Search
 * Weblink: https://leetcode.com/explore/learn/card/binary-search/138/background/1038/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int bsearch(std::vector<int>& nums, int target, int start, int end)
    {
        int mid = start + (end - start) / 2;
        if (start > end) {
            return -1;
        }
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bsearch(nums, target, mid + 1, end);
        } else {
            return bsearch(nums, target, start, mid - 1);
        }
    }
    int search(vector<int>& nums, int target) {
        return bsearch(nums, target, 0, nums.size() - 1);
    }
};
