#include <iostream>
#include <string>
#include <string.h>

int main(void)
{
    std::string filename = "/home/karthick";
    std::size_t pos;

    std::cout << "C string length = " << strlen("/home/karthick") << std::endl;
    std::cout << "String: " << filename << " Length: " << filename.length() << std::endl;
    std::cout << filename << std::endl;
    pos = filename.find("/");
    std::cout << "Position: " << pos << std::endl;

    std::cout << filename.substr(pos + 1) << std::endl;
    pos = filename.find("/", pos + 1);
    std::cout << "Position: " << pos << std::endl;

    std::cout << filename.substr(pos + 1) << std::endl;
    pos = filename.find("/", pos + 1);
    if(pos < filename.length())
    {
        std::cout << "Position: " << pos << std::endl;
        std::cout << filename.substr(pos + 1) << std::endl;
    }

    return 0;
}
