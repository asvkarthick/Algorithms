/* Program to move zeroes to the end of the array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                k++;
            }
        }
    }
};
