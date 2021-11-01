/* Problem: Interval List Intersections
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
            int minl1 = firstList[i][0];
            int maxl1 = firstList[i][1];
            int minl2 = secondList[j][0];
            int maxl2 = secondList[j][1];
            if (maxl1 >= minl2 && minl1 <= minl2) {
                result.push_back(std::vector<int>{minl2, std::min(maxl2, maxl1)});
                if (maxl1 < maxl2)
                    i++;
                else
                    j++;
            } else if (maxl2 >= minl1 && minl2 <= minl1) {
                result.push_back(std::vector<int>{minl1, std::min(maxl2, maxl1)});
                if (maxl1 < maxl2)
                    i++;
                else
                    j++;
            } else if (minl1 < minl2 && maxl1 < minl2) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
