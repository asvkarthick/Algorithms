/* Problem: Longest substring without repeated characters
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3008/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <unordered_set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0, maxLength = 0;
        std::unordered_set<char> hashSet;
        int leftIndex = -1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            auto it = hashSet.find(ch);
            if (it == hashSet.end()) {
                hashSet.insert(ch);
                length++;
            } else {
                while (s[++leftIndex] != ch) {
                    length--;
                    it = hashSet.find(s[leftIndex]);
                    hashSet.erase(it);
                }
            }
            if (length > maxLength) maxLength = length;
        }
        return maxLength;
    }
};

int main()
{
	Solution s;
	std::string str = "tmmzuxt";
	int len = s.lengthOfLongestSubstring(str);
	std::cout << "Max length = " << len << std::endl;
	return 0;
}
