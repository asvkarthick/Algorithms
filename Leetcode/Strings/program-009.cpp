/* Program to find the given string is anagram of another string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> m;
        if (s.length() != t.length()) return false;
        for (auto ch : s) m[ch] = m[ch] + 1;
        for (auto ch : t) m[ch] = m[ch] - 1;
        for (auto &p : m) {
            if (p.second != 0) return false;
        }
        return true;
    }
};
