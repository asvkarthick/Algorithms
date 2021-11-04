/* Problem: Roman to Integer
 * Weblink: https://leetcode.com/problems/roman-to-integer/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> hashMap;
        int idx;
        int result;

        /* Fill hashMap with roman to integer mapping */
        hashMap['I'] = 1;
        hashMap['V'] = 5;
        hashMap['X'] = 10;
        hashMap['L'] = 50;
        hashMap['C'] = 100;
        hashMap['D'] = 500;
        hashMap['M'] = 1000;

        idx = s.length() - 1;
        result = hashMap[s[idx]];

        while (idx > 0) {
            if (hashMap[s[idx]] > hashMap[s[idx - 1]]) {
                result -= hashMap[s[idx - 1]];
            } else {
                result += hashMap[s[idx - 1]];
            }
            idx--;
        }

        return result;
    }
};
