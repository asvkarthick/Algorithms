#include <iostream>
#include <string>

int main(void)
{
    std::string s = "Karthick";
    std::string::iterator i = s.begin();

    while(*i != '\0')
        std::cout << *i++;
    std::cout << std::endl;

    return 0;
}
