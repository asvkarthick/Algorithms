/* Program: Fibonacci
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1661/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int fib(std::vector<int>& v, int n)
    {
        if (n <= 1) {
            v[n] = n;
            return n;
        }
        if (v[n] != -1) {
            return v[n];
        } else {
            v[n] = fib(v, n - 1) + fib(v, n - 2);
            return v[n];
        }
    }
    int fib(int n) {
        std::vector<int> v(n + 1, -1);
        if (n <= 1) return n;
        return fib(v, n);
    }
};
