/* Vector lower_bound problem
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    std::vector<int> v;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        v.push_back(num);
    }

    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int num;
        std::cin >> num;
        auto it = std::lower_bound(v.begin(), v.end(), num);
        if (*it == num) {
            std::cout << "Yes " << it - v.begin() + 1 << std::endl;
        } else {
            std::cout << "No " << it - v.begin() + 1 << std::endl;
        }
    }
    return 0;
}
