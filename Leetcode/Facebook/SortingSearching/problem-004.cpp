/* Problem: Find first and last position of element in sorted array
 * Weblink: 
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int searchRange(std::vector<int>& nums, int start, int end, int target, bool isFirst)
    {
        int mid = start + (end - start) / 2;
        if (start > end) return -1;
        if (nums[mid] == target) {
            if (isFirst) {
                if (mid == start || nums[mid - 1] != target)
                    return mid;
                return searchRange(nums, start, mid - 1, target, isFirst);
            } else {
                if (mid == end || nums[mid + 1] != target)
                    return mid;
                return searchRange(nums, mid + 1, end, target, isFirst);
            }
        } else if (nums[mid] < target) {
            return searchRange(nums, mid + 1, end, target, isFirst);
        } else {
            return searchRange(nums, start, mid - 1, target, isFirst);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = searchRange(nums, 0, nums.size() - 1, target, true);
        int end = searchRange(nums, 0, nums.size() - 1, target, false);
        return std::vector<int> { start, end };
    }
};
