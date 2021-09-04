/* Problem-200 : Count the number of islands
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void parseIsland(vector<vector<char>>& grid, int i, int j)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        parseIsland(grid, i, j + 1);
        parseIsland(grid, i + 1, j);
        parseIsland(grid, i - 1, j);
        parseIsland(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    parseIsland(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};
