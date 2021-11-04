/* Problem: Multiply Strings
 * Weblink: https://leetcode.com/problems/multiply-strings/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        std::string result(num1.size() + num2.size(), '0');
        int product = 0, carry = 0, sum = 0;
        int dstIndex, k = 0;
        if (num1 == "0" || num2 == "0") return "0";

        if (num1.length() < num2.length())
            return multiply(num2, num1);

        for (int i = num1.length() - 1; i >= 0; i--, k++) {
            int n1 = num1[i] - '0';
            dstIndex = result.length() - 1 - k;
            carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                product = n1 * n2 + carry;
                carry = product / 10;
                product = product % 10;
                sum = product + result[dstIndex] - '0';
                carry += sum / 10;
                sum = sum % 10;
                result[dstIndex] = sum + '0';
                dstIndex--;
            }
            if (carry) result[dstIndex] = carry + '0';
        }

        // Remove leading zeros
        int i = 0;
        while (result[i] == '0') i++;
        result = result.substr(i);

        return result;

    }
};
