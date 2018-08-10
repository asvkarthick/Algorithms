#include <iostream>
#include <stack>

/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true

*/

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        std::stack<int> st;
        int i;
        if(!n)
            return true;
        
        for(i = 0; i < n; i++)
        {
            char ch = s.at(i);
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(ch == ')' || ch == '}' || ch == ']')
            {
                if(st.empty())
                    return false;
                if(ch == ')' && st.top() != '(')
                    return false;
                if(ch == '}' && st.top() != '{')
                    return false;
                if(ch == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};

int main(void)
{
    Solution s;

    std::cout << s.isValid(std::string {"()"}) << std::endl;
    std::cout << s.isValid(std::string {"()[]{}"}) << std::endl;
    std::cout << s.isValid(std::string {"(]"}) << std::endl;
    std::cout << s.isValid(std::string {"([)]"}) << std::endl;
    std::cout << s.isValid(std::string {"{[]}"}) << std::endl;

    return 0;
}
