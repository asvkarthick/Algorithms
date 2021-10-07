/* Problem: Letter combinations of a phone number
 * Weblink: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void letterCombinations(const std::string& digits, int start, std::vector<std::string>& combs, const std::string numPad[], std::string prefix)
    {
        if (prefix.length() == digits.length()) {
            combs.push_back(prefix);
            return;
        }
        int index = digits[start] - '0';
        for (int i = 0; i < numPad[index].size(); i++) {
            letterCombinations(digits, start + 1, combs, numPad, prefix + numPad[index][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        std::string numPad[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        std::vector<std::string> combs;
        if (digits.length() == 0) return combs;
        letterCombinations(digits, 0, combs, numPad, "");
        return combs;
    }
};
