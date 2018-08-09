#include <iostream>
#include <string>

/*

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.


*/

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, sign = 1, len = str.length();
        int isFirstSign = 0;
        std::string out;
        int result = 0;
        
        if(!len)
            return 0;
        
        while(i < len)
        {
            if(str.at(i) == '-')
            {
                if(isFirstSign)
                    break;
                isFirstSign = 1;
                if(out.length() == 0)
                    sign = -1;
                else
                    break;
            }
            else if(str.at(i) >= '0' && str.at(i) <= '9')
            {
                out.push_back(str.at(i));
            }
            else if(str.at(i) == '+')
            {
                if(isFirstSign)
                    break;
                isFirstSign = 1;
            }
            else if(str.at(i) == ' ')
            {
                if(out.length() != 0)
                    break;
            }
            else if(str.at(i) != ' ' && str.at(i) != '+')
            {
                break;
            }
            i++;
        }
        
        for(i = 0; i < out.length(); i++)
        {
            // if(result >= 0xCCCCCCC && out.at(i) > '7')
            if(result >= 0xCCCCCCC)
            {
                if(sign == -1)
                    result = 0x80000000;
                else
                    result = 0x7FFFFFFF;
                return result;
            }
            result = (result * 10) + out.at(i) - '0';
        }

        return sign * result;
    }
};

int main(void)
{
    Solution s;
    std::string s1 { "42" };
    std::string s2 { "   -42" };
    std::string s3 { "4193 with words" };
    std::string s4 { "words and 987" };
    std::string s5 { "-91283472332" };
    std::string s6 { "2147483648" };
    std::string s7 { "2147483646" };

    std::cout << s.myAtoi(s1) << std::endl;
    std::cout << s.myAtoi(s2) << std::endl;
    std::cout << s.myAtoi(s3) << std::endl;
    std::cout << s.myAtoi(s4) << std::endl;
    std::cout << s.myAtoi(s5) << std::endl;
    std::cout << s.myAtoi(s6) << std::endl;
    std::cout << s.myAtoi(s7) << std::endl;

    return 0;
}
