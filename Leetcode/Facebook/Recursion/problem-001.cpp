/* Problem: Permutations
 * Weblink: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/292/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void permute(std::vector<int> &nums, std::vector<std::vector<int>> &v)
    {
        if (temp.size() == nums.size()) {
            v.push_back(std::vector<int>(temp.begin(), temp.end()));
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
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> v;
        temp.clear();
        for (int i = 0; i < nums.size(); i++) used.push_back(false);
        permute(nums, v);
        return v;
    }
    std::vector<bool> used;
    std::deque<int> temp;
};
