/* Program-014 : Longest common prefix
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string lcp = "";
        if (strs.size() <= 0) return lcp;
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != ch) return lcp;
            }
            lcp += ch;
        }
        return lcp;
    }
};
