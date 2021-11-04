/* Problem: Next Permutation
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3012/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void reverse(vector<int>& a, int start)
    {
    	int i = start, j = a.size() - 1;
        while (i < j) {
        	int t = a[i];
        	a[i] = a[j];
        	a[j] = t;
        	i++;
        	j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }
        i--;
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) j--;
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
        reverse(nums, i + 1);
    }
};
