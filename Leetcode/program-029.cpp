/* Problem: Divide two integers
 * Weblink: https://leetcode.com/problems/divide-two-integers/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        int HALF_INT_MIN = INT_MIN ^ (1 << 30);
        if (dividend == 0 || divisor == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        int result = 0;
        bool resFlag = false;
        if (dividend > 0) {
            resFlag ^= true;
            dividend = -dividend;
        }
        if (divisor > 0) {
            resFlag ^= true;
            divisor = -divisor;
        }

        while (dividend <= divisor) {
            int powerOfTwo = -1;
            int value = divisor;

            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value = value + value;
                powerOfTwo = powerOfTwo + powerOfTwo;
            }

            result += powerOfTwo;
            dividend -= value;
        }

        if (!resFlag) result = -result;

        return result;
    }
};
