/* Program to validate sudoku
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int arr[9];
        /* Check each row */
        for (int row = 0; row < board.size(); row++) {
            for (int i = 0; i < 9; i++) arr[i] = 0;
            for (int col = 0; col < board.size(); col++) {
                if (board[row][col] != '.') arr[board[row][col] - '1']++;
            }
            for (int i = 0; i < 9; i++) {
                if (arr[i] > 1) return false;
            }
        }
        /* Check each col */
        for (int col = 0; col < board.size(); col++) {
            for (int i = 0; i < 9; i++) arr[i] = 0;
            for (int row = 0; row < board.size(); row++) {
                if (board[row][col] != '.') arr[board[row][col] - '1']++;
            }
            for (int i = 0; i < 9; i++) {
                if (arr[i] > 1) return false;
            }
        }
        /* Check each 3 * 3 */
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                for (int i = 0; i < 9; i++) arr[i] = 0;
                for (int row = r; row < r + 3; row++) {
                    for (int col = c; col < c + 3; col++) {
                        if (board[row][col] != '.') arr[board[row][col] - '1']++;
                    }
                }
                for (int i = 0; i < 9; i++) {
                    if (arr[i] > 1) return false;
                }
            }
        }
        return true;
    }
};
