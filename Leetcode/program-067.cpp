#include <iostream>
#include <string>

/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

using namespace std;

class Solution {
public:
    void add(char bit1, char bit2, char& carry, char& sum)
    {
        if(carry == '0')
        {
            if(bit1 == '0' && bit2 == '0')
            {
                sum = '0';
                carry = '0';
            }
            else if(bit1 == '0' && bit2 == '1')
            {
                sum = '1';
                carry = '0';
            }
            else if(bit1 = '1' && bit2 == '0')
            {
                sum = '1';
                carry = '0';
            }
            else if(bit1 = '1' && bit2 == '1')
            {
                sum = '0';
                carry = '1';
            }
        }
        else
        {
            if(bit1 == '0' && bit2 == '0')
            {
                sum = '1';
                carry = '0';
            }
            else if(bit1 == '0' && bit2 == '1')
            {
                sum = '0';
                carry = '1';
            }
            else if(bit1 = '1' && bit2 == '0')
            {
                sum = '0';
                carry = '1';
            }
            else if(bit1 = '1' && bit2 == '1')
            {
                sum = '1';
                carry = '1';
            }
        }
    }
    
    string addBinary(string a, string b) {
        std::string output;
        int max_length = std::max(a.length(), b.length());
        int min_length = std::min(a.length(), b.length());
        int i, j, k, l;
        char sum, carry = '0';
        
        j = a.length() - 1;
        k = b.length() - 1;
        l = max_length - 1;

        if(a.length() > b.length())
            output = a;
        else
            output = b;

        for(i = 0; i < min_length; i++)
        {
            add(a.at(j), b.at(k), carry, sum);
            output.at(l) = sum;
            --l;
            --j;
            --k;
        }
        
        while(j >= 0)
        {
            add(a.at(j), '0', carry, sum);
            output.at(l) = sum;
            --l;
            --j;
        }
        
        while(k >= 0)
        {
            add(b.at(k), '0', carry, sum);
            output.at(l) = sum;
            --l;
            --k;
        }
        
        if(carry == '1')
            output = '1' + output;
        
        return output;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.addBinary(std::string {"11"}, std::string{"1"}) << std::endl;
    std::cout << s.addBinary(std::string {"1010"}, std::string{"1011"}) << std::endl;

    return 0;
}
