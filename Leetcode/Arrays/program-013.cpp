/* Find the year of maximum population
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <map>

static int findMaxPopulationYear(std::vector<std::pair<int, int>>& p)
{
    int mp = 0;
    int min = 0, max = 0;
    int maxPopulationYear = 0;
    std::map<int, int> mpy;
    if (p.size() == 0) return mp;
    for (int i = 0; i < p.size(); i++) {
        auto& pr = p[i];
        if (pr.first < min) min = pr.first;
        if (pr.second > max) max = pr.second;
        for (int j = pr.first; j <= pr.second; j++) {
            mpy[j] = mpy[j] + 1;
        }
    }
    for (auto it = mpy.begin(); it != mpy.end(); it++) {
        if (mp < it->second) {
            mp = it->second;
            maxPopulationYear = it->first;
        }
    }
    return maxPopulationYear;
}

int main(void)
{
    int n;
    int birth, death;
    std::vector<std::pair<int, int>> p;
    std::cout << "Enter the number of persons : ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> birth;
        std::cin >> death;
        p.push_back(std::make_pair(birth, death));
    }
    auto mp = findMaxPopulationYear(p);
    std::cout << "Max population year = " << mp << std::endl;
    return 0;
}
