/* Problem: Implement strstr()
 * Weblink: https://leetcode.com/problems/implement-strstr/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;
        size_t pos;
        if ((pos = haystack.find(needle)) != std::string::npos)
            return pos;
        return -1;
    }
};
