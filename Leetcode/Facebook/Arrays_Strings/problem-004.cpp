/* Problem: Move zeroes
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/262/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            nums[j++] = nums[i];
        }
        for (i = j; i < nums.size(); i++) nums[i] = 0;
    }
};
