#include <iostream>
#include <vector>

/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.

*/

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col, row;
        
        if(matrix.size() <= 0)
            return false;
        
        col = matrix[0].size() - 1;
        row = 0;
        
        while(col >= 0 && row < matrix.size()) {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                ++row;
            else
                --col;
        };
        return false;
    }
};

int main(void)
{
    Solution s;

    std::vector<std::vector<int>> v { {  1,  4,  7, 11, 15 },
                                      {  2,  5,  8, 12, 19 },
                                      {  3,  6,  9, 16, 22 },
                                      { 10, 13, 14, 17, 24 },
                                      { 18, 21, 23, 26, 30 }
                                    };

    std::cout << s.searchMatrix(v, 5) << std::endl;
    std::cout << s.searchMatrix(v, 20) << std::endl;

    return 0;
}
