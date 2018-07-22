#include <iostream>
#include <string>

void ReverseString(std::string& s, int i)
{
    char c;
    if(i == s.length())
        return;

    c = s.at(i);
    ReverseString(s, i + 1);
    s.at(s.length() - 1 - i) = c;
    std::cout << c << " " << i << std::endl;
}

int main(void)
{
    std::string s { "Karthick" };
    int i;

    for(i = 0; i < s.length(); i++)
        std::cout << s.at(i) << std::endl;

    std::cout << std::endl;
    ReverseString(s, 0);
    std::cout << std::endl;


    for(i = 0; i < s.length(); i++)
        std::cout << s.at(i) << std::endl;

    return 0;
}
