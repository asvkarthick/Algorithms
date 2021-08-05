/* Program to find the intersection of two arrays
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        map<int, int> m1, m2;
        for(int i = 0; i < nums1.size(); i++) {
            m1[nums1[i]] = m1[nums1[i]] + 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            m2[nums2[i]] = m2[nums2[i]] + 1;
        }
        for (auto &x : m1) {
            int n1 = x.second;
            int n2 = m2[x.first];
            int mini = std::min(n1, n2);
            for (int i = 0; i < mini; i++) {
            	v.push_back(x.first);
            }
        }
        return v;
    }
};

int main(void)
{
	Solution s;
	vector<int> v1 { 1, 2, 3, 4 , 4 };
	vector<int> v2 { 1, 4, 4, 3, 0, 1 };
	auto v = s.intersect(v1, v2);
	for (auto x : v) std::cout << x << std::endl;
	return 0;
}
