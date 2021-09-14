/* Problem: Reverse a string
 * Weblink: https://leetcode.com/explore/featured/card/recursion-i/250/principle-of-recursion/1440/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void reverseString(vector<char>& s, int i) {
        if (i == s.size()) return;
        char ch = s[i];
        reverseString(s, i + 1);
        s[s.size() - i - 1] = ch;
    }
    void reverseString(vector<char>& s) {
        reverseString(s, 0);
    }
};
