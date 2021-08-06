/* Implement strstr - 2
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) return i;
        }
        return -1;
    }
};
