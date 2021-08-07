/* Program to find if a substring is present in text
 * Implement strstr()
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/* Program to implement strstr using hash
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
#include <map>

int strstr(std::string haystack, std::string needle)
{
    std::map<std::string, int> hash;
    if (needle.length() == 0) return 0;
    if (haystack.length() < needle.length()) return 0;
    hash[needle] = 1;
    for (int i = 0; i < haystack.length(); i++) {
        std::string str = haystack.substr(i, needle.length());
	if (hash[str]) return i;
    }
    return -1;
}

int main(void)
{
    std::string haystack, needle;
    std::cout << "Enter the string : ";
    getline(std::cin, haystack);
    std::cout << "Enter search string : ";
    getline(std::cin, needle);
    std::cout << haystack << std::endl;
    std::cout << needle << std::endl;
    std::cout << strstr(haystack, needle) << std::endl;
    return 0;
}
