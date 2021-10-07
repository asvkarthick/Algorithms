/* Problem: Search in rotated sorted array
 * Weblink: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/279/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int search(std::vector<int>& nums, int start, int end, int target)
    {
        int mid = start + (end - start) / 2;
        if (start > end) return -1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] >= nums[start]) {
            if (target >= nums[start] && target <= nums[mid])
                return search(nums, start, mid - 1, target);
            else
                return search(nums, mid + 1, end, target);
        } else {
            if (target >= nums[mid] && target <= nums[end])
                return search(nums, mid + 1, end, target);
            else
                return search(nums, start, mid - 1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};
