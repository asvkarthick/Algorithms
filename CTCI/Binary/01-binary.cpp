/* Program to convert fixed number to string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>

static std::string convert(double num)
{
    std::string s = ".";
    if (num == 0) return "ERROR";
    while (num > 0) {
        if (s.length() > 32) return "ERROR";
        std::cout << s << " num = " << num << std::endl;
        double r = num * 2;
        if (r >= 1.0) {
            s += "1";
            num = r - 1;
        } else {
            s += "0";
            num = r;
        }
    }
    return s;
}

int main(void)
{
    double d;
    std::cout << "Enter a number : ";
    std::cin >> d;
    std::cout << "Converted = " << convert(d) << std::endl;
    return 0;
}
