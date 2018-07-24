#include <iostream>

/*

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 - 1) or INT_MIN (-2^31) is returned.
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
             Thefore INT_MIN (-2^31) is returned.

*/

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int string_length = str.length();
        int i, number, sign = 1;
        int integer = 0;
        bool isFirstSign = true;

        for(i = 0; i < string_length; i++)
        {
            char ch = str.at(i);
            if(ch >= '0' && ch <= '9')
            {
                number = ch - '0';
            }
            else if(ch == '-')
            {
                sign = -1;
                if(!isFirstSign)
                    return sign * integer;
                isFirstSign = false;
                continue;
            }
            else if(ch == ' ')
            {
                continue;
            }
            else if(ch == '+')
            {
                if(!isFirstSign)
                    return sign * integer;
                isFirstSign = false;
                continue;
            }
            else
            {
                return sign * integer;
            }

            if(integer > (0x7FFFFFFF / 10))
            {
                if(sign == 1)
                    return 0x7FFFFFFF;
                else
                    return 0x80000000;
            }
            integer = integer * 10 + ch - '0';
        }

        return sign * integer;
    }
};

int main(void)
{
    Solution s;
    std::cout << s.myAtoi(std::string { "42" }) << std::endl;
    std::cout << s.myAtoi(std::string { "   -42" }) << std::endl;
    std::cout << s.myAtoi(std::string { "4193 with words" }) << std::endl;
    std::cout << s.myAtoi(std::string { "words and 987" }) << std::endl;
    std::cout << s.myAtoi(std::string { "-91283472332" }) << std::endl;

    return 0;
}
