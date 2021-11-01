/* Problem: Interval List Intersections - Another solution
 * Weblink: https://leetcode.com/explore/interview/card/facebook/57/others-3/3043/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int l1size = firstList.size();
        int l2size = secondList.size();
        std::vector<std::vector<int>> result;
        if (l1size == 0 || l2size == 0) return result;

        int i = 0, j = 0;
        while (i < l1size && j < l2size) {
            int low = std::max(firstList[i][0], secondList[j][0]);
            int high = std::min(firstList[i][1], secondList[j][1]);
            if (low <= high)
                result.push_back(std::vector<int>{low, high});
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }

        return result;
    }
};
