/* Problem: Find min path sum from Point-A to Point-B
 * Weblink: https://leetcode.com/problems/minimum-path-sum/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (row == 0 && col == 0) {
                    grid[row][col] = grid[row][col];
                } else if (col == 0 && row != 0) {
                    grid[row][col] = grid[row - 1][col] + grid[row][col];
                } else if (row == 0 && col != 0) {
                    grid[row][col] = grid[row][col] + grid[row][col - 1];
                } else {
                    grid[row][col] = std::min(grid[row - 1][col], grid[row][col - 1]) + grid[row][col];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
