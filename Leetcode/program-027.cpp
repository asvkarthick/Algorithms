/* Program-027 : Remove element from array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};
