#include <iostream>
#include <string>

/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

*/

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        int n = s.length();
        int count[26] = { 0 };
        
        for(int i = 0; i < n; i++)
        {
            count[s.at(i) - 'a']++;
            count[t.at(i) - 'a']--;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(count[i])
                return false;
        }
        
        return true;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.isAnagram(std::string {"anagram"}, std::string {"nagaram"}) << std::endl;
    std::cout << s.isAnagram(std::string {"rat"}, std::string {"car"}) << std::endl;

    return 0;
}
