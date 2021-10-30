/* Problem: Count Island
 * Weblink: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/274/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void clearIsland(std::vector<std::vector<char>> &grid, int row, int col)
    {
        if (row < 0 || col < 0) return;
        if (row >= grid.size() || col >= grid[0].size()) return;
        if (grid[row][col] != '1') return;
        grid[row][col] = '0';
        clearIsland(grid, row, col + 1);
        clearIsland(grid, row, col - 1);
        clearIsland(grid, row + 1, col);
        clearIsland(grid, row - 1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    ++islandCount;
                    clearIsland(grid, row, col);
                }
            }
        }
        return islandCount;
    }
};
