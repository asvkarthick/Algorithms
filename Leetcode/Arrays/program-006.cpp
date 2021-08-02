/* Program to find the indexes of two indexes whose sum equals target
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> m;
        if (nums.size() < 2) return v;
        for (auto i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return v;
    }
};
