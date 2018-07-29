#include <iostream>
#include <vector>

/*

We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:

Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Example 2:

Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

*/

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        bool last_bit = false;
        
        while(i < bits.size()) {
            if(bits[i] == 0) {
                i++;
                last_bit = true;
            } else {
                i += 2;
                last_bit = false;
            }
        }
        
        return last_bit;
    }
};

int main(void)
{
    std::vector<int> v1 { 1, 0, 0 };
    std::vector<int> v2 { 1, 1, 1, 0 };
    Solution s;

    std::cout << s.isOneBitCharacter(v1) << std::endl;
    std::cout << s.isOneBitCharacter(v2) << std::endl;

    return 0;
}
