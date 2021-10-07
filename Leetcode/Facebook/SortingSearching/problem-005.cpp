/* Problem: Merge Intervals
 * Weblink: https://leetcode.com/problems/merge-intervals/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> merged;
        std::sort(intervals.begin(), intervals.end());
        for (auto &interval : intervals) {
            if (merged.size() == 0 || merged[merged.size() - 1][1] < interval[0])
                merged.push_back(interval);
            else
                merged[merged.size() - 1][1] = std::max(merged[merged.size() - 1][1], interval[1]);
        }
        return merged;
    }
};
