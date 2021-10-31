/* Problem: SubArray Sum Equals K
 * Weblink: https://leetcode.com/problems/subarray-sum-equals-k/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numSubsets = 0;
        int sum = 0;
        std::unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hashMap.find(sum - k) != hashMap.end()) {
                numSubsets += hashMap[sum - k];
            }
            hashMap[sum] = hashMap[sum] + 1;
        }

        return numSubsets;
    }
};
