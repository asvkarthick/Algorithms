/* Urlify - Replace spaces with %20
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
#include <string.h>

int numSpaces(const char *str, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') count++;
    }
    return count;
}

void urlify(char *str, int n)
{
    int spaces = numSpaces(str, n);
    int dstIndex, srcIndex;
    dstIndex = n + 2 * spaces - 1;
    srcIndex = n - 1;
    str[dstIndex + 1] = '\0';
    for (int i = 0; i < n; i++) {
        if (str[srcIndex] != ' ') {
            str[dstIndex--] = str[srcIndex--];
        } else {
            str[dstIndex] = '0';
            str[dstIndex - 1] = '2';
            str[dstIndex - 2] = '%';
            dstIndex -= 3;
            srcIndex--;
        }
    }
}

int main(void)
{
    std::string str;
    char *s;
    std::cout << "Enter string with spaces : ";
    getline(std::cin, str);
    std::cout << "String = " << str << std::endl;
    std::cout << "String length = " << str.length() << std::endl;
    int spaces = numSpaces(str.c_str(), str.length());
    s = (char*) new char[2 * spaces + str.length() + 1];
    strcpy(s, str.c_str());
    urlify(s, str.length());
    std::cout << "Urlified string = " << s << std::endl;
    return 0;
}
