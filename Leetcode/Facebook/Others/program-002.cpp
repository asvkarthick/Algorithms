/* Problem: Find All Anagrams in a string
 * Weblink: https://leetcode.com/explore/interview/card/facebook/57/others-3/3040/
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
    
    vector<int> findAnagrams(string s, string p) {
        int sfreq[N], pfreq[N];
        std::vector<int> result;
        if (p.length() > s.length()) return result;
        
        for (int i = 0; i < N; i++) {
            sfreq[i] = 0;
            pfreq[i] = 0;
        }
        for (int i = 0; i < p.length(); i++) {
            sfreq[s[i] - 'a'] += 1;
            pfreq[p[i] - 'a'] += 1;
        }
        
        for (int i = 0; i < s.length() - p.length(); i++) {
            if (isMatch(sfreq, pfreq)) result.push_back(i);
            sfreq[s[i] - 'a']--;
            sfreq[s[i + p.length()] - 'a']++;
        }
        if (isMatch(sfreq, pfreq)) result.push_back(s.length() - p.length());
        
        return result;
    }
};
