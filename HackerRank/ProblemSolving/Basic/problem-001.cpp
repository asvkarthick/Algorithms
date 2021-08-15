#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'decryptPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
bool isDigit(char ch)
{
    return (ch >= '1' && ch <= '9');
}

bool isUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

bool isLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

string decryptPassword(string s) {
    std::string decryptPwd = "";
    std::stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (isDigit(s[i])) {
            st.push(s[i]);
            continue;
        }
        if (s[i] == '0') {
            decryptPwd += st.top();
            st.pop();
        } else if (isUpper(s[i]) && i + 2 < s.length() && isLower(s[i + 1]) && s[i + 2] == '*') {
            decryptPwd += s[i + 1];
            decryptPwd += s[i];
            i = i + 2;
        } else {
            decryptPwd += s[i];
        }
    }
    return decryptPwd;
}

int main() {}
