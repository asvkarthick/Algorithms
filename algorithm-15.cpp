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
}

int main(void)
{
    std::string s { "Karthick" };
    int i;

    std::cout << "Original string: " << s << std::endl;
    ReverseString(s, 0);
    std::cout << "Reversed string: " << s << std::endl;

    return 0;
}
