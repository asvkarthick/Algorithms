/* Problem: Square of sorted array
 * Weblink: https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3240/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> result(nums.size());

        // Find first positive
        int posIndex = nums.size(), negIndex = nums.size() - 1, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                posIndex = i;
                break;
            }
        }
        negIndex = posIndex - 1;
        while (negIndex >= 0 && posIndex < nums.size()) {
            if (nums[posIndex] < -nums[negIndex]) {
                result[k++] = nums[posIndex] * nums[posIndex];
                posIndex++;
            } else {
                result[k++] = nums[negIndex] * nums[negIndex];
                negIndex--;
            }
        }
        while (posIndex < nums.size()) {
            result[k++] = nums[posIndex] * nums[posIndex];
            posIndex++;
        }
        while (negIndex >= 0) {
            result[k++] = nums[negIndex] * nums[negIndex];
            negIndex--;
        }
        return result;
    }
};
