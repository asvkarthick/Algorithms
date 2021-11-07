/* Problem: Search a 2D matrix
 * Weblink: https://leetcode.com/problems/search-a-2d-matrix/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0) return false;

        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int start = 0, end = numRows * numCols - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / numCols;
            int col = mid % numCols;
            if (target == matrix[row][col])
                return true;
            else if (target > matrix[row][col])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};
