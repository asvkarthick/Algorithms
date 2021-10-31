/* Program: Range Sum Query - 2D
 * Weblink: https://leetcode.com/problems/range-sum-query-2d-immutable/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;

        for (int i = 0; i < matrix.size() + 1; i++) mMatrix.push_back(std::vector<int>(matrix[0].size() + 1));

        for (int row = 0; row < matrix.size() + 1; row++) mMatrix[row][0] = 0;
        for (int col = 0; col < matrix[0].size() + 1; col++) mMatrix[0][col] = 0;

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                int sum = 0;
                for (int r = 0; r < row + 1; r++) sum += matrix[r][col];
                mMatrix[row + 1][col + 1] = mMatrix[row + 1][col] + sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return mMatrix[row2 + 1][col2 + 1] - mMatrix[row1][col2 + 1] - mMatrix[row2 + 1][col1] + mMatrix[row1][col1];
    }
    std::vector<std::vector<int>> mMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
