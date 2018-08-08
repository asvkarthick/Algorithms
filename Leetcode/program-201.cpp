#include <iostream>

/*


Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 1;
        int range = n - m;
        if(n == m)
            return n & m;

        while(range != 0)
        {
            n = (n >> i) << i;
            ++i;
            range = range >> 1;
        }

        return n & m;
    }
};
