/* Program to rotate array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz <= 1) return;
        k = k % sz;
        /* Reverse the whole array */
        for (int i = 0; i < sz / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[sz - 1 - i];
            nums[sz - 1 - i] = temp;
        }
        /* Reverse the first k numbers */
        for (int i = 0; i < k / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[k - 1 - i];
            nums[k - 1 - i] = temp;
        }
        /* Reverse the remaining numbers */
        for (int i = k; i < (sz + k) / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[sz - i + k - 1];
            nums[sz - i + k - 1] = temp;
        }
    }
};
