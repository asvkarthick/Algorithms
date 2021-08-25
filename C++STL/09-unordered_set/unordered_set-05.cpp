/* Program to find if a pair of numbers present in set
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <unordered_set>
#include <vector>

bool hasPairSum(const std::vector<int>& v, int sum)
{
	std::unordered_set<int> s;
	for (auto x : v) {
		if (s.find(x) != s.end()) {
			return true;
		}
		s.insert(sum - x);
	}
	return false;
}

int main(void)
{
	std::vector<int> v1 { 1, 2, 4, 4 };
	std::vector<int> v2 { 1, 2, 7, 9 };
	std::vector<int> v3 { 1, 2, 3, 4 };
	int sum = 8;
	
	if (hasPairSum(v1, sum))
	    std::cout << "v1 has the pair" << std::endl;
	else
	    std::cout << "v1 does not have the pair" << std::endl;
	    
	if (hasPairSum(v2, sum))
	    std::cout << "v2 has the pair" << std::endl;
	else
	    std::cout << "v2 does not have the pair" << std::endl;
	    
	if (hasPairSum(v3, sum))
	    std::cout << "v3 has the pair" << std::endl;
	else
	    std::cout << "v3 does not have the pair" << std::endl;
	
	return 0;
}
