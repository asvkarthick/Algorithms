/* Basic string program to access each character
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	std::string s = "Karthick";

	// Access each character
	for (char ch : s) std::cout << ch;
	std::cout << std::endl;

	// Access each character in another method
	for (int i = 0; i < s.length(); i++) std::cout << s[i];
	std::cout << std::endl;

	return 0;
}
