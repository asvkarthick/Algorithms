#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <algorithm>

/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int len = 0;
        int i, n = s.length();
        std::deque<char> q;

        for(i = 0; i < n; i++)
        {
            if(std::find(q.begin(), q.end(), s.at(i)) != q.end())
            {
                if(max_len < len)
                    max_len = len;
                while(q.front() != s.at(i))
                {
                    q.pop_front();
                    --len;
                }
                q.pop_front();
                --len;
            }
            ++len;
            q.push_back(s.at(i));
        }

        if(len > max_len)
            max_len = len;

        return max_len;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring(std::string { "abcabcbb" } ) << std::endl;
    std::cout << s.lengthOfLongestSubstring(std::string { "bbbbb" } ) << std::endl;
    std::cout << s.lengthOfLongestSubstring(std::string { "pwwkew" } ) << std::endl;

    return 0;
}
