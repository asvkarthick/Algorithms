/* Problem: Remove repeated numbers in an array
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3011/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        // Nothing to do if size of array <= 1
        if (nums.size() <= 1) return nums.size();

        // Remove repeated numbers
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[j]) {
                continue;
            } else {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};
