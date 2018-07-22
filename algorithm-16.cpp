#include <iostream>
#include <string>

void ReverseString(std::string& s)
{
    char c;
    int i;

    for(i = 0; i < s.length() / 2; i++)
    {
        c = s.at(i);
        s.at(i) = s.at(s.length() - 1 - i);
        s.at(s.length() - 1 - i) = c;
    }
}

int main(void)
{
    std::string s { "Karthick" };
    int i;

    for(i = 0; i < s.length(); i++)
        std::cout << s.at(i) << std::endl;

    std::cout << std::endl;
    ReverseString(s);
    std::cout << std::endl;


    for(i = 0; i < s.length(); i++)
        std::cout << s.at(i) << std::endl;

    return 0;
}
