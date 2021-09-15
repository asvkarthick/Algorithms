/* Program: Fibonacci
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1661/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};
