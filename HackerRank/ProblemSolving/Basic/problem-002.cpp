#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

bool isVowel(char s)
{
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int countVowels(std::string& s)
{
    int vowels = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i]))
            vowels++;
    }
    return vowels;
}

string findSubstring(string s, int k) {
    std::string substr = "Not found!";
    int numVowels = 0;
    if (k > s.length())
        return std::string("Not found!");
    std::string temp = s.substr(0, k);
    numVowels = countVowels(temp);
    if (numVowels) substr = temp;
    int maxVowels = numVowels;
    for (int i = 1; i < s.length() - k; i++) {
        if (isVowel(s[i - 1])) numVowels--;
        if (isVowel(s[i + k - 1])) numVowels++;
        if (numVowels > maxVowels) {
            maxVowels = numVowels;
            substr = s.substr(i, k);
        }
    }
    return substr;
}

int main() {}
