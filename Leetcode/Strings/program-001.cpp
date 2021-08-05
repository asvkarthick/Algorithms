/* Program to reverse individual words in string
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
using namespace std;

void reverse(std::string &s, int start, int end)
{
	if (end < start || end > s.length()) return;
	while (start < end) {
		auto temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

void reverse(std::string &s)
{
	int start = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			reverse(s, start, i - 1);
			start = i + 1;
		}
	}
	reverse(s, start, s.length() - 1);
}

int main()
{
	std::string s;
	getline(std::cin, s);
	std::cout << "Name = " << s << std::endl;
	// reverse(s, 0, s.length() - 1);
	reverse(s);
	std::cout << "Reversed name = " << s << std::endl;
	return 0;
}
