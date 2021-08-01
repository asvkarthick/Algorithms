/* Program to add one
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] = digits[i] + carry;
            if (!carry) break;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
