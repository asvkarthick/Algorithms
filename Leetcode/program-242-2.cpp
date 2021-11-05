/* Problem: Valid Anagram
 * Weblink: https://leetcode.com/problems/valid-anagram/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int result = 0;
        if (s.length() != t.length()) return false;
        std::unordered_map<char, int> hashMap;

        for (auto ch : s)
            hashMap[ch] = hashMap[ch] + 1;

        for (auto ch : t) {
            if (hashMap.find(ch) == hashMap.end()) {
                return false;
            } else {
                hashMap[ch] = hashMap[ch] - 1;
                if (hashMap[ch] < 0) return false;
            }
        }

        return true;
    }
};
