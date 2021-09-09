/* Problem: Add Binary
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/263/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int sum, carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        std::string output = "";

        while (i >= 0 && j >= 0) {
            int num1 = a[i] - '0';
            int num2 = b[j] - '0';
            i--;
            j--;
            sum = num1 + num2 + carry;
            carry = sum >> 1;
            sum = sum & 0x1;
            output = std::to_string(sum) + output;
        }
        while (i >= 0) {
            int num = a[i] - '0';
            i--;
            sum = num + carry;
            carry = sum >> 1;
            sum = sum & 0x1;
            output = std::to_string(sum) + output;
        }
        while (j >= 0) {
            int num = b[j] - '0';
            j--;
            sum = num + carry;
            carry = sum >> 1;
            sum = sum & 0x1;
            output = std::to_string(sum) + output;
        }
        if (carry) output = '1' + output;
        return output;
    }
};
