#include <iostream>
#include <vector>

/*

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

*/

using namespace std;

class Solution {
public:

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i, j, k;
        std::vector<std::vector<int>> v(A.size());

        for(i = 0; i < A.size(); i++)
        {
            for(k = 0, j = A[i].size() - 1; j >= 0; j--, k++)
            {
                v[i].push_back(!A[i][j]);
            }
        }

        return v;
    }
};

int main(void)
{
    Solution s;
    std::vector<std::vector<int>> A { {1, 1, 0}, { 1, 0, 1 }, { 0, 0, 0 } };
    int i, j;
    std::vector<std::vector<int>> v = s.flipAndInvertImage(A);

    for(i = 0; i < v.size(); i++)
    {
        for(j = 0; j < v[i].size(); j++)
        {
            std::cout << v[i][j] < " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
