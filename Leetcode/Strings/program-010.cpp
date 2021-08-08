/* Program to find the first unique character location
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char, int> m;
        for (auto ch : s) m[ch] = m[ch] + 1;
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};
