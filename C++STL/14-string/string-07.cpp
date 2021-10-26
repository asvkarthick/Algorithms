/* Program: Extract words with delimiter " " from a string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "abc def ghi jkl";
    size_t prevpos = 0, curpos = 0;
    while (true) {
        curpos = str.find(" ", prevpos);
        if (curpos != std::string::npos) {
            std::string tmp = str.substr(prevpos, curpos - prevpos + 1);
            std::cout << tmp << std::endl;
        } else {
	    std::string tmp = str.substr(prevpos);
	    std::cout << tmp << std::endl;
            break;
        }
        prevpos = curpos + 1;
    }
    return 0;
}
