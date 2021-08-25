/* Connected Cells in a Grid
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int countArea(vector<vector<int>>& v, long unsigned int i, long unsigned int j)
{
    int count = 0;
    if (i < 0 || j < 0) return 0;
    if (i >= v.size()) return 0;
    if (j >= v[0].size()) return 0;
    if (v[i][j] == 0) return 0;
    v[i][j] = 0;
    /* Current pixel */
    count += 1;
    /* Left pixel */
    count += countArea(v, i, j - 1);
    /* Right pixel */
    count += countArea(v, i, j + 1);
    /* Bottom pixel */
    count += countArea(v, i + 1, j);
    /* Diagonal pixels */
    count += countArea(v, i + 1, j + 1);
    count += countArea(v, i + 1, j - 1);
    count += countArea(v, i - 1, j - 1);
    count += countArea(v, i - 1, j + 1);
    return count;
}

int connectedCell(vector<vector<int>> matrix) {
    int count = 0;
    for (auto i = 0UL; i < matrix.size(); i++) {
        for (auto j = 0UL; j < matrix[0].size(); j++) {
            int cnt = countArea(matrix, i, j);
            if (cnt > count) count = cnt;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> v { {1, 1, 1, 0, 1},
                            {0, 0, 1, 0, 0},
                            {1, 1, 0, 1, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0},
                            {0, 0, 1, 1, 0} };
    std::cout << "Count = " << connectedCell(v) << std::endl;
    return 0;
}
