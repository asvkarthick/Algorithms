#include <iostream>
#include <vector>

/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> intermediate;
        std::vector<int> output;
        int carry = 1, sum, n = digits.size(), i;
        
        for(i = n - 1; i >= 0; i--)
        {
            sum = carry + digits[i];
            carry = (sum / 10);
            sum = (sum % 10);
            intermediate.push_back(sum);
        }
        
        if(carry)
            output.push_back(1);
        for(i = n - 1; i >= 0; i--)
            output.push_back(intermediate[i]);
        
        return output;
    }
};

int main(void)
{
    std::vector<int> v1 { 1, 2, 3 };
    std::vector<int> v2 { 9, 9, 9 };
    Solution s;

    auto v3 = s.plusOne(v1);
    auto v4 = s.plusOne(v2);

    for(auto elem : v3)
        std::cout << elem <<  " ";
    std::cout << std::endl;

    for(auto elem : v4)
        std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}
