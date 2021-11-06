/* Problem: pow(x, n)
 * Weblink: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/3031/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    double power(double x, int n)
    {
        if (n == 0) return 1.0;

        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {
        if (x == 0) return x;
        if (n == 0) return 1.0;
        if (n < 0) {
            x = 1 / x;
            n = std::abs(n);
        }

        double result = power(x, n);

        return result;
    }
};
