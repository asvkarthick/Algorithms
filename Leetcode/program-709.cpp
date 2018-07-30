#include <iostream>
#include <string>

/*

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"

*/

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.length(); i++) {
            char ch = str.at(i);
            if(ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;
                str.at(i) = ch;
            }
        }
        return str;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.toLowerCase(std::string { "Hello" }) << std::endl;
    std::cout << s.toLowerCase(std::string { "here" }) << std::endl;
    std::cout << s.toLowerCase(std::string { "LOVELY" }) << std::endl;

    return 0;
}
