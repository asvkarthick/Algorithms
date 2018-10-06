#include <iostream>
#include <string>

std::string findLongestRepeatedSubstring(std::string s)
{
    int i, j;
    int len = s.length();

    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j <= i; j++)
        {
            std::string str1 = s.substr(j, len - i - 1);
            std::string str2 = s.substr(j + 1, len - (j + 1));
            if(str2.find(str1) != std::string::npos)
                return str1;
            // std::cout << "str1 = " << str1 << std::endl;
            // std::cout << "str2 = " << str2 << std::endl;
        }
    }

    return std::string("NULL");
}

int main(void)
{
    std::cout << findLongestRepeatedSubstring(std::string("xoxoxo")) << std::endl;
    std::cout << findLongestRepeatedSubstring(std::string("abcdef")) << std::endl;
    return 0;
}
