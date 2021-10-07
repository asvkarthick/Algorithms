/* Problem: Intersection of two arrays
 * Weblink: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/3033/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    std::vector<int> findIntersection(std::unordered_set<int> &hashSet, std::vector<int>& nums)
    {
        std::unordered_set<int> res;
        for (auto& x : nums) {
            if (hashSet.find(x) != hashSet.end()) {
                res.insert(x);
            }
        }
        return std::vector<int>(res.begin(), res.end());
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> hashSet;
        if (nums1.size() <= nums2.size()) {
            for (auto& x : nums1)
                hashSet.insert(x);
            return findIntersection(hashSet, nums2);
        } else {
            for (auto& x: nums2)
                hashSet.insert(x);
            return findIntersection(hashSet, nums1);
        }
    }
};
