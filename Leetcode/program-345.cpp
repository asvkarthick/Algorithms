#include <iostream>
#include <string>

using namespace std;

/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y". 

*/

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int length = s.length();
        int i = 0, k = length - 1;
        
        while(i < k)
        {
            if(!isVowel(s.at(i)))
                ++i;
            if(!isVowel(s.at(k)))
                --k;
            if(isVowel(s.at(i)) && isVowel(s.at(k)))
            {
                char ch = s.at(i);
                s.at(i) = s.at(k);
                s.at(k) = ch;
                ++i;
                --k;
            }
        }
        
        return s;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.reverseVowels(std::string { "hello" }) << std::endl;

    return 0;
}
