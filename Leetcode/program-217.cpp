#include <iostream>
#include <unordered_set>
#include <vector>

/*

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> d;

        for(auto elem : nums) {
            if(d.find(elem) != d.end())
                return true;
            d.insert(elem);
        }
        
        return false;
    }
};

int main(void)
{
    std::vector<int> v1 { 1, 2, 3, 1 };
    std::vector<int> v2 { 1, 2, 3, 4 };
    Solution s;

    std::cout << s.containsDuplicate(v1) << std::endl;
    std::cout << s.containsDuplicate(v2) << std::endl;

    return 0;
}
