/* Program: Monotonic Array
 * Weblink: https://leetcode.com/problems/monotonic-array/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasingMonotonic = true;
        bool decreasingMonotonic = true;
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (min >= nums[i])
                min = nums[i];
            else
                decreasingMonotonic = false;
            if (max <= nums[i])
                max = nums[i];
            else
                increasingMonotonic = false;
            if (decreasingMonotonic == false && increasingMonotonic == false)
                return false;
        }
        return increasingMonotonic || decreasingMonotonic;
    }
};
