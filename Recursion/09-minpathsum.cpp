/* Program: Find the min path sum from Point-A to Point-B
 * Weblink: https://leetcode.com/problems/minimum-path-sum/solution/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
	int minSum;
	int numPaths;
	void minPathSum(std::vector<std::vector<int>>& grid, int row, int col, int sum)
	{
		if (row >= grid.size() || col >= grid[0].size()) return;
		if (row == grid.size() - 1 && col == grid[0].size() - 1) {
			numPaths++;
			if (sum + grid[row][col] < minSum) minSum = sum + grid[row][col];
		}
		minPathSum(grid, row + 1, col, sum + grid[row][col]);
		minPathSum(grid, row, col + 1, sum + grid[row][col]);
	}
	int minPathSum(std::vector<std::vector<int>>& grid)
	{
		minSum = INT_MAX;
		numPaths = 0;
		minPathSum(grid, 0, 0, 0);
		return minSum;
	}
	int getNumPaths()
	{
		return numPaths;
	}
};

int main(void)
{
	Solution s;
	std::vector<std::vector<int>> grid { {1, 3, 1}, { 1, 5, 1 }, { 4, 2, 1 } };
	std::cout << "Min path sum = " << s.minPathSum(grid) << std::endl;
	std::cout << "Num Paths = " << s.getNumPaths() << std::endl;
	return 0;
}
