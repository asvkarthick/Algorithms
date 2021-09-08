/* Insert and erase operations in unordered set
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	std::unordered_set<int> us;
	us.insert(10);
	us.insert(20);
	us.insert(30);
	us.insert(40);
	for (auto x : us) std::cout << x << std::endl;
	std::cout << "Removing some elements" << std::endl;
	auto it = us.find(10);
	if (it != us.end()) us.erase(it);
	for (auto x : us) std::cout << x << std::endl;
	return 0;
}
