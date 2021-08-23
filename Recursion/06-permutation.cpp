/* Program to print all permutations of a string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>

static std::vector<bool> used;
static std::string str;
static std::string instr;

void permute()
{
    if (str.length() == instr.length()) {
        std::cout << str << std::endl;
        return;
    }
    for (auto i = 0; i < instr.length(); i++) {
        std::string s = str;
        if (used[i]) continue;
	// str.append(instr.at(i));
	str.append(instr, i, 1);
        used[i] = true;
        permute();
        used[i] = false;
        str = s;
    }
}

void permute(std::string &s)
{
    for (auto i = 0; i < s.length(); i++) {
        used.push_back(false);
    }
    instr = s;
    permute();
}

int main(void)
{
    std::string s;
    std::cout << "Enter a string : ";
    std::cin >> s;
    std::cout << "String = " << s << std::endl;
    std::cout << "Length of string = " << s.length() << std::endl;
    permute(s);
    return 0;
}
