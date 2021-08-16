/* Sorting a string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    std::string s = "karthick";
    std::sort(s.begin(), s.end());
    std::cout << s;
    return 0;
}
