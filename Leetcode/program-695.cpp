/* Program: Max area of an island
 * Weblink: https://leetcode.com/problems/max-area-of-island/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int count1AndClearIsland(std::vector<std::vector<int>>& grid, int row, int col)
    {
        int leftCount, rightCount, topCount, bottomCount;
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        leftCount = count1AndClearIsland(grid, row, col - 1);
        rightCount = count1AndClearIsland(grid, row, col + 1);
        topCount = count1AndClearIsland(grid, row - 1, col);
        bottomCount = count1AndClearIsland(grid, row + 1, col);
        return 1 + leftCount + rightCount + topCount + bottomCount;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col]) {
                    int area = count1AndClearIsland(grid, row, col);
                    if (area > maxArea) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
