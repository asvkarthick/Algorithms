/* Problem: Climbing stairs
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1662/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int climbStairs(int n, std::vector<int>& v)
    {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (v[n] != 0) {
            return v[n];
        } else {
            v[n] = climbStairs(n - 1, v) + climbStairs(n - 2, v);
            return v[n];
        }
    }
    int climbStairs(int n) {
        std::vector<int> v(n + 1, 0);
        return climbStairs(n, v);;
    }
};
