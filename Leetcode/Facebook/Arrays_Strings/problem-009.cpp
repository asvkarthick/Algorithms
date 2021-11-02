/* Problem: 3 sum
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/283/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> res;
        std::unordered_set<int> duplicates;
        std::unordered_set<int> seenInI;

        for (int i = 0; i < nums.size(); i++) {
            auto it1 = duplicates.find(nums[i]);
            if (it1 == duplicates.end()) {
                duplicates.insert(nums[i]);
                seenInI.clear();
                for (int j = i + 1; j < nums.size(); j++) {
                    int complement = -nums[i] - nums[j];
                    auto it2 = seenInI.find(complement);
                    if (it2 != seenInI.end()) {
                        std::vector<int> v { nums[i], nums[j], complement };
                        sort(v.begin(), v.end());
                        res.insert(v);
                    }
                    seenInI.insert(nums[j]);
                }
            }
        }
        return std::vector<std::vector<int>>(res.begin(), res.end());
    }
};
