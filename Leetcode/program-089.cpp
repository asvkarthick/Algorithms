#include <iostream>
#include <vector>

/*

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1

Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].

*/

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> v;
        int value, new_value, bit1, bit2;

        for(int i = 0; i < (1 << n); i++) {
            value = i;
            new_value = i & (1 << (n - 1));
            for(int j = n - 2; j >= 0; --j) {
                bit1 = (value & (1 << (j + 1))) >> 1;
                bit2 = (value & (1 << j));
                new_value |= bit1 ^ bit2;
            }
            v.push_back(new_value);
        }

        return v;
    }
};

void print(std::vector<int>& v)
{
    for(auto elem : v)
        std::cout << elem << std::endl;
}

int main(void)
{
    std::vector<int> v1, v2, v3;
    Solution s;

    std::cout << "Printing 2 bit gray code" << std::endl;
    v1 = s.grayCode(2);
    print(v1);
    std::cout << "Printing 0 bit gray code" << std::endl;
    v2 = s.grayCode(0);
    print(v2);
    std::cout << "Printing 3 bit gray code" << std::endl;
    v3 = s.grayCode(3);
    print(v3);

    return 0;
}
