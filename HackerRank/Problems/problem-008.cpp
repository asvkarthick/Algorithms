#include <iostream>
#include <vector>
using namespace std;

static void reverse(vector<int>& a, int beg, int sz)
{
	int end = beg + sz - 1;
    for (int i = beg; i < end; i++) {
        int t = a[i];
        a[i] = a[end];
        a[end--] = t;
    }
}

vector<int> rotLeft(vector<int> a, int d) {
    /* Rotate the whole array first */
    reverse(a, 0, a.size());
    for (auto x : a) std::cout << x << " ";
    std::cout << std::endl;
    /* Reverse the first n - d elements separately */
    reverse(a, 0, a.size() - d);
    for (auto x : a) std::cout << x << " ";
    std::cout << std::endl;
    /* Reverse the remaining (d) elements */
    reverse(a, a.size() - d, d);
    for (auto x : a) std::cout << x << " ";
    std::cout << std::endl;
    return a;
}

int main() {
	// your code goes here
	std::vector<int> a { 1, 2, 3, 4, 5 };
	auto v = rotLeft(a, 4);
	for (auto x : v) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}
