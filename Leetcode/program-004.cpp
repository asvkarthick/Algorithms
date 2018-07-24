#include <iostream>

/*

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
==========
Input: 123
Output: 321

Example 2:
==========
Input: -123
Output: -321

Example 3:
==========
Input: 120
Output: 21

*/

class Solution {
public:
    int reverse(int x) {
        int reversed_number = 0;
        int sign = x > 0 ? 1 : -1;

        x = x * sign;

        while(x > 0)
        {
            // if(reversed_number > 0xCCCCCCC)
            if(reversed_number > (0x7FFFFFFF / 10))
                return 0;

            reversed_number = reversed_number * 10 + (x % 10);
            x = x / 10;
        }

        reversed_number *= sign;

        return reversed_number;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(120) << std::endl;

    return 0;
}
