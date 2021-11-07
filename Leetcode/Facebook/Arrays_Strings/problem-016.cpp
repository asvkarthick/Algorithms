/* Problem: Valid Palindrome II
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/289/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isPalindrome(string s, int low, int high, int sum)
    {
        if (sum > 1) return false;
        while (low < high && s[low] == s[high]) {
            low++;
            high--;
        }
        if (low >= high) return true;

        return isPalindrome(s, low + 1, high, sum + 1) || isPalindrome(s, low, high - 1, sum + 1);
    }

    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.length() - 1, 0);
    }
};
