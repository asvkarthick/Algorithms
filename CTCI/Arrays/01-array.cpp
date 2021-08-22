/* Check if two strings are permutation of each other
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
#include <algorithm>

bool isPermute(std::string s1, std::string s2)
{
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) return false;
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
    if (isPermute(s1, s2))
        std::cout << s1 << " and " << s2 << " are permuted" << std::endl;
    else
        std::cout << s1 << " and " << s2 << " are not permuted" << std::endl;
    return 0;
}
