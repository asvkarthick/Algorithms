/* Problem: Recursion - Subsets (Backtracking)
 * Weblink: https://leetcode.com/problems/subsets/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void formSubsets(std::vector<std::vector<int>>& result, std::list<int>& l, int n, int k, int start, std::vector<int>& nums)
    {
        if (l.size() == k) {
            result.push_back(std::vector<int>(l.begin(), l.end()));
            return;
        }

        for (int i = start; i < n; i++) {
            l.push_back(nums[i]);
            formSubsets(result, l, n, k, i + 1, nums);
            l.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::list<int> l;
        if (nums.size() == 0) return result;
        for (int i = 0; i <= nums.size(); i++) {
            formSubsets(result, l, nums.size(), i, 0, nums);
        }
        return result;
    }
};
