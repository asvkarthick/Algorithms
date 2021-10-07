/* Problem: Permutations II
 * Weblink: https://leetcode.com/problems/permutations-ii/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void permute(std::vector<int> &nums, std::set<std::vector<int>> &v)
    {
        if (temp.size() == nums.size()) {
            v.insert(std::vector<int>(temp.begin(), temp.end()));
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            permute(nums, v);
            used[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::set<std::vector<int>> v;
        temp.clear();
        for (int i = 0; i < nums.size(); i++) used.push_back(false);
        permute(nums, v);
        return std::vector<std::vector<int>>(v.begin(), v.end());
    }
    std::vector<bool> used;
    std::deque<int> temp;
};
