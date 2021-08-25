/* Phone Number program
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    int n;
    std::unordered_map<std::string, int> hashMap;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string name;
        int phoneno;
        std::cin >> name;
        std::cin >> phoneno;
        hashMap[name] = phoneno;
    }
    std::string name;
    while (std::cin >> name) {
        auto it = hashMap.find(name);
        if (it != hashMap.end()) {
            int phoneno = it->second;
            std::cout << name << "=" << phoneno << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    return 0;
}
