/* Problem: Range sum query - 1D
 * Weblink: https://leetcode.com/problems/range-sum-query-immutable/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums.reserve(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
    std::vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
