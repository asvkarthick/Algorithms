#include <iostream>
#include <map>

int main(void) {
    std::multimap<double, int> m = {
	    {1.1, 3}, {2.2, 5}, {0.5, 3}};
    m.insert(std::make_pair<double, int>(0.0, 6));
    for (auto & x : m) {
        std::cout << x.first << " : " << x.second << std::endl;
    }
}
