#include <iostream>

unsigned char input[][6] = {
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 1},
};

void parseIsland(int i, int j, int rows, int cols)
{
    // std::cout << "parseIsland " << i << " , " << j << std::endl;
    if (input[i][j] == 0) return;
    input[i][j] = 0;
    if (j + 1 < cols) parseIsland(i, j + 1, rows, cols);
    if (i + 1 < rows) parseIsland(i + 1, j, rows, cols);
    if (j > 0) parseIsland(i, j - 1, rows, cols);
}

int countIslands()
{
    int islandCount = 0;
    int rows = sizeof(input) / sizeof(input[0]);
    int cols = sizeof(input) / sizeof(input[0][0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (input[i][j] == 1) {
                ++islandCount;
                std::cout << "Found an island at " << i << " , " << j << " Num Island = " << islandCount << std::endl;
                parseIsland(i, j, rows, cols);
            }
        }
    }
    return islandCount;
}

int main(void)
{
    int numIslands;
    std::cout << "Count island program" << std::endl;
    std::cout << "sizeof(input) = " << sizeof(input) << std::endl;
    std::cout << "sizeof(input[0]) = " << sizeof(input[0]) << std::endl;
    numIslands = countIslands();
    std::cout << "Number of islands = " << numIslands << std::endl;
    return 0;
}
