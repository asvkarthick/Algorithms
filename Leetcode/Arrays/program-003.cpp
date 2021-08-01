/* Program to find the number that is present only once
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto i : nums) {
            x = x ^ i;
        }
        return x;
    }
};
