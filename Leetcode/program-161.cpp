/* Problem: One Edit Distance
 * Weblink: https://leetcode.com/problems/one-edit-distance/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sIndex = 0, tIndex = 0;
        if (std::abs((int)(s.length() - t.length())) > 1) return false;
        int numMismatches = 0;

        if (s.length() > t.length())
            return isOneEditDistance(t, s);

        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] != t[tIndex]) {
                numMismatches++;
                if (numMismatches > 1) return false;
                if (s.length() < t.length()) {
                    tIndex++;
                } else {
                    sIndex++;
                    tIndex++;
                }
            } else {
                sIndex++;
                tIndex++;
            }
        }
        numMismatches += (t.length() - tIndex);

        return numMismatches == 1;
    }
};
