/* Program to remove duplicate elements in sorted array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int k = 1;
        int min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= min) continue;
            nums[k++] = nums[i];
            min = nums[i];
        }
        return k;
    }
};
