/* Program to find a string is palindrome by checking only alphanumeric characters
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isAlphaNumeric(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    char lower(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return c;
    }
    bool isPalindrome(string s) {
        int n = 0;
        /* Remove non alphanumeric characters */
        for (int i = 0; i < s.length(); i++) {
            if (isAlphaNumeric(s[i])) {
                s[n++] = lower(s[i]);
            }
        }
        int length = n;
        /* Check if it is palindrome or not */
        int i = 0;
        while (i < length) {
            if (s[i] != s[length - 1]) return false;
            i++;
            length--;
        }
        return true;
    }
};
