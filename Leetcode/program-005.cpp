#include <iostream>
#include <string>

/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

*/

using namespace std;

class Solution {
public:
    int palindromeLength(std::string& s, int mid1, int mid2)
    {
        while(mid1 >= 0 && mid2 < s.length() && s.at(mid1) == s.at(mid2))
        {
            mid1--;
            mid2++;
        }
        
        return mid2 - mid1 - 1;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        int max_len = 0, i,l, start = 0;
        std::string palindrome;

        if(len <= 1)
            return s;
        
        for(i = 0; i < len; i++)
        {
            // For odd length palindrome
            l = palindromeLength(s, i, i);
            if(l > max_len)
            {
                max_len = l;
                start = i - (l / 2);
                // std::cout << "Odd Start = " << start << " l = " << l << " i = " << i << std::endl;
            }
            
            // For even length palindrome
            l = palindromeLength(s, i, i + 1);
            if(l > max_len)
            {
                max_len = l;
                start = i - (l / 2) + 1;
                // std::cout << "Even Start = " << start << " l = " << l << " i = " << i << std::endl;
            }
        }

        len = 0;
        while(len < max_len)
        {
            palindrome.push_back(s.at(start));
            ++start;
            ++len;
        }

        return palindrome;
    }
};

int main(void)
{
    Solution s;
    std::string str1 { "babad" };
    std::string str2 { "cbbd" };

    std::cout << s.longestPalindrome(str1) << std::endl;
    std::cout << s.longestPalindrome(str2) << std::endl;

    return 0;
}
