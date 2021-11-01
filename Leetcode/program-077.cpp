/* Problem: Combinations
 * Weblink: https://leetcode.com/explore/learn/card/recursion-ii/472/backtracking/2798/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void formCombinations(std::vector<std::vector<int>>& result, std::list<int>& l, int n, int k, int start)
    {
        if (l.size() == k) {
            result.push_back(std::vector<int>(l.begin(), l.end()));
            return;
        }
        for (int i = start; i < n + 1; i++) {
            l.push_back(i);
            formCombinations(result, l, n, k, i + 1);
            l.back();
            l.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::list<int> l;
        if (k == 0) return result;
        formCombinations(result, l, n, k, 1);
        return result;
    }
};
