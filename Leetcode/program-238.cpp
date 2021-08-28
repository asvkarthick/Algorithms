/* LC-238: Product of Array except Self
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int productSofar = 1;
        
        /* Compute the product from the front */
        for (int i = 0; i < nums.size(); i++) {
            result[i] = productSofar;
            productSofar *= nums[i];
        }
        
        /* Compute the product from backwards */
        productSofar = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= productSofar;
            productSofar *= nums[i];
        }
        
        return result;
    }
};
