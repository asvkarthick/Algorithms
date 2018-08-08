#include <iostream>

/*

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh". 

*/

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++)
        {
            char ch = s.at(i);
            s.at(i) = s.at(n - i - 1);
            s.at(n - i - 1) = ch;
        }
        return s;
    }
};

int main(void)
{
    std::string str { "hello" };
    Solution s;

    std::cout << s.reverseString(str) << std::endl;

    return 0;
}
