/* Program to find duplicates
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if (m[nums[i]] > 1) return true;
        }
        return false;
    }
};
