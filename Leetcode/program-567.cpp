/* Problem: Permutations in a string
 * Weblink: https://leetcode.com/problems/permutation-in-string/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    const int N = 26;
    bool isMatch(int *s1, int *s2)
    {
        for (int i = 0; i < N; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int s1freq[N], s2freq[N];
        if (s1.length() > s2.length()) return false;

        for (int i = 0; i < N; i++) {
            s1freq[i] = 0;
            s2freq[i] = 0;
        }
        for (int i = 0; i < s1.length(); i++) {
            s1freq[s1[i] - 'a'] += 1;
            s2freq[s2[i] - 'a'] += 1;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (isMatch(s1freq, s2freq)) return true;
            s2freq[s2[i] - 'a']--;
            s2freq[s2[i + s1.length()] - 'a']++;
        }

        return isMatch(s1freq, s2freq);
    }
};
