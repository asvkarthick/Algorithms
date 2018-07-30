#include <iostream>
#include <list>
#include <string>
#include <stack>

/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

*/

using namespace std;

class Solution {
private:
    stack<string> s;
public:
    string simplifyPath(string path) {
        string ans="";
        string dir="";
        stringstream p(path);
        
        while(getline(p, dir, '/')) {
            if (dir != "" && dir != "." && dir != "..")
                s.push(dir);
            else if (dir == ".." && !s.empty())
                s.pop();
        }
        
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        if (ans == "")
            return "/";
        return ans;
    }
};

int main(void)
{
    std::string str = "/home/karthick";
    Solution s;

    std::cout << s.simplifyPath(str) << std::endl;

    return 0;
}
