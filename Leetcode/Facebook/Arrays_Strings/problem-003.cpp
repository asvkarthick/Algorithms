/* Merge Sorted Array
 * Problem: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/309/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int dstIndex = m + n - 1;
        int src1 = m - 1;
        int src2 = n - 1;
        // Compare both array from the end and start storing in nums1 end
        while (src2 >= 0 && src1 >= 0) {
            if (nums1[src1] > nums2[src2]) {
                nums1[dstIndex] = nums1[src1--];
            } else {
                nums1[dstIndex] = nums2[src2--];
            }
            dstIndex--;
        }
        // Add the remaining numbers from nums2
        while (src2 >= 0) {
            nums1[dstIndex--] = nums2[src2--];
        }
    }
};
