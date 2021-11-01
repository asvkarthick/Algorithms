/* Problem: Verifying an Alien Dictionary
 * Weblink: https://leetcode.com/explore/interview/card/facebook/57/others-3/3042/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::unordered_map<char, int> hashMap;

        for (int i = 0; i < order.length(); i++) {
            char ch = order[i];
            hashMap[ch] = i;
        }

        std::string prevString = "";
        int prevStringLen = 0, curStringLen = 0;
        for (auto& str : words) {
            int i = 0, j = 0;
            curStringLen = str.length();
            while (i < prevStringLen && j < curStringLen) {
                if (hashMap[prevString[i]] < hashMap[str[j]]) break;
                if (hashMap[prevString[i]] > hashMap[str[j]]) return false;
                i++;
                j++;
            }
            if (i == str.length() && prevStringLen > str.length()) return false;
            prevStringLen = curStringLen;
            prevString = str;
        }

        return true;
    }
};
