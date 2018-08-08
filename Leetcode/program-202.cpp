#include <iostream>
#include <unordered_set>

/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> s;

        int num = 0;

        while(true)
        {
            num = 0;
            while(n > 0)
            {
                int last_digit = n % 10;
                n = n / 10;
                num = num + (last_digit * last_digit);
            }
            if(num == 1)
                return true;
            if(s.find(num) != s.end())
                return false;
            s.insert(num);
            n = num;
        }

        return false;
    }
};

/*
 * Using Floyd Cycle Detection Algorithm
 *
class Solution {
public:
    int countSquareSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int last_digit = n % 10;
            n = n / 10;
            sum = sum + (last_digit * last_digit);
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do
        {
            slow = countSquareSum(slow);
            fast = countSquareSum(fast);
            fast = countSquareSum(fast);
        } while(slow != fast);

        return slow == 1;
    }
};

*/
