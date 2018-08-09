#include <iostream>
#include <vector>

/*

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> v(numRows);
        if(numRows == 0)
            return v;
        
        v[0].push_back(1);
        for(int i = 1; i < numRows; i++)
        {
            int j;
            int k = 0;
            v[i].push_back(1);
            for(j = 1; j < i; j++)
            {
                v[i].push_back(v[i - 1][k] + v[i - 1][k + 1]);
                k++;
            }
            v[i].push_back(1);
        }
        
        return v;
    }
};

int main(void)
{
    Solution s;

    auto v = s.generate(5);

    return 0;
}
