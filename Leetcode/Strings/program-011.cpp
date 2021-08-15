/* Program to find if two words are one edit distance or not
 * An edit is
 * - Inserting one character anywhere in the word
 * - Removing one character
 * - Replacing one character
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <string>
#include <iostream>

static bool checkEdit(std::string& s1, std::string& s2)
{
    int numMismatch = 0;
    int s1index = 0;
    int s2index = 0;
    if (std::abs((int)s1.length() - (int)s2.length()) > 1) return false;
    int minLength = std::min(s1.length(), s2.length());
    for (int i = 0; i < minLength; i++) {
        if (s1[s1index] == s2[s2index]) {
            s1index++;
            s2index++;
        } else {
            numMismatch++;
            if (numMismatch > 1) return false;
            if (s1index + 1 < s1.length() && s2index + 1 < s2.length()) {
                if (s1[s1index + 1] == s2[s2index])
                    s1index++;
                else if (s2[s1index + 1] == s1[s1index])
                    s2index++;
                else {
                    s1index++;
                    s2index++;
                }
            }
        }
    }
    return true;
}

int main(void)
{
    std::string s1, s2;
    std::cout << "Enter string-1 : ";
    std::cin >> s1;
    std::cout << "Enter string-2 : ";
    std::cin >> s2;

    if (checkEdit(s1, s2))
        std::cout << s1 << " and " << s2 << " are one edit distance" << std::endl;
    else
        std::cout << s1 << " and " << s2 << " are not one edit distance" << std::endl;

    return 0;
}
