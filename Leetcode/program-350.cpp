/* Problem: Intersection of Two Arrays II
 * Weblink: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> hashMap;
        std::vector<int> result;

        if (nums2.size() < nums1.size())
            return intersect(nums2, nums1);

        for (int i = 0; i < nums1.size(); i++) {
            hashMap[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            int val;
            auto it = hashMap.find(nums2[i]);
            if (it != hashMap.end()) {
                hashMap[nums2[i]]--;
                val = hashMap[nums2[i]];
                if (val == 0)
                    hashMap.erase(it);
                result.push_back(nums2[i]);
            }
        }

        return result;
    }
};
