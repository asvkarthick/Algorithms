/* Program to compute nth element of look and say sequence
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>

// Equivalent to std::to_string
std::string strnum(int count)
{
    if (count == 0) return "";
    char c = (count % 10) + '0';
    std::string s(1, c);
    return s + strnum(count / 10);
}

std::string compute(int n)
{
    std::string s;
    std::string temp = "1";
    if (n < 0) return "";
    if (n == 1) return temp;
    int count;
    while (n > 1) {
        s = "";
        count = 1;
        for (int i = 1; i <= temp.length(); i++) {
            if (i == (temp.length()) || temp[i] != temp[i - 1]) {
                s += std::to_string(count) + temp[i - 1];
                count = 1;
            } else {
                count++;
            }
        }
        n--;
        temp = s;
    }
    return s;
}
int main(void)
{
    int n;
    std::cout << "Enter n : ";
    std::cin >> n;
    std::cout << compute(n) << std::endl;
    return 0;
}
