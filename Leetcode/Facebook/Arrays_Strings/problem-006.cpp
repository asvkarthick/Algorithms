/* Problem: Prodcut of Array except self
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3016/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output(nums.size());
        int product = 1;
        // Forward product
        for (int i = 0; i < nums.size(); i++) {
            output[i] = product * nums[i];
            product = product * nums[i];
        }

        // Reverse product
        product = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            output[i] = product * output[i - 1];
            product = product * nums[i];
        }
        output[0] = product;
        return output;
    }
};
