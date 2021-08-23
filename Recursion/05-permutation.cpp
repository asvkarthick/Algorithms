/* Permutations of a string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>

void permutation(std::string s, std::string prefix)
{
    if (s.length() == 0) {
        std::cout << prefix << std::endl;
    } else {
        for (int i = 0; i < s.length(); i++) {
            std::string rem = s.substr(0, i) + s.substr(i + 1);
            permutation(rem, prefix + s[i]);
        }
    }
}

void permutation(std::string& s)
{
    std::string prefix = "";
    permutation(s, prefix);
}

int main(void)
{
    std::string s;
    std::cout << "Enter string : ";
    std::cin >> s;
    permutation(s);
    return 0;
}
