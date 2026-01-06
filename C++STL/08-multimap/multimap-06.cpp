#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <math.h>

std::multimap<double, int> closestPoints;

std::vector<std::tuple<int, int>> findPclosest(std::vector<std::tuple<int, int>>& xyPlane, int P) {
    for (int i = 0; i < xyPlane.size(); i++) {
        // auto distance = sqrt(xyPlane[i].first * xyPlane[i].first + xyPlane[i].second * xyPlane[i].second);
        double distance = sqrt(std::get<0>(xyPlane[i]) * std::get<0>(xyPlane[i]) + std::get<1>(xyPlane[i]) * std::get<1>(xyPlane[i]));
	closestPoints.insert(std::pair(distance, i));
    }

    std::vector<std::tuple<int, int>> v;
    auto it = closestPoints.begin();
    for (int i = 0; i < P; i++) {
        auto & [key, value] = *it++;
        v.push_back(xyPlane[value]);
    }
    return v;
}

int main(void) {
    std::vector<std::tuple<int, int>> xyPlane = {std::pair(1, 2), std::pair(1, 1), std::pair(3, 3), std::pair(-1, 2), std::pair(4, 4), std::pair(0, 0), std::pair(0, 4)};

    auto v = findPclosest(xyPlane, 4);
    for (int i = 0; i < v.size(); i++) {
        std::cout << std::get<0>(v[i]) << ", " << std::get<1>(v[i]) << std::endl;
    }
    return 0;
}
