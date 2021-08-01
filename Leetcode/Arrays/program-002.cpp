/* Program to rotate an image 90 degrees
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if (size <= 1) return;
        for (auto row = 0; row < (size + 1) / 2; row++) {
            for (auto col = 0; col < size / 2; col++) {
                int temp = matrix[size - 1 - col][row];
                matrix[size - 1 - col][row] = matrix[size - 1 - row][size - 1 - col];
                matrix[size - 1 - row][size - 1 - col] = matrix[col][size - 1 - row];
                matrix[col][size - 1 - row] = matrix[row][col];
                matrix[row][col] = temp;
            }
        }
    }
};
