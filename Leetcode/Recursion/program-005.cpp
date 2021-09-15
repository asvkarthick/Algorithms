/* Program: Pascal's triangle using recursion
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3234/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    void pascalTriangle(std::vector<int>& v1, std::vector<int>& v2, int rowNo, int colNo, int finalRow)
    {
        if (rowNo == finalRow + 1) return;
        if (colNo == 0) {
            v1.clear();
            v1.push_back(1);
        }
        if (colNo == rowNo) {
            if (colNo != 0) v1.push_back(1);
            pascalTriangle(v2, v1, rowNo + 1, 0, finalRow);
        } else {
            if (colNo != 0) v1.push_back(v2[colNo - 1] + v2[colNo]);
            pascalTriangle(v1, v2, rowNo, colNo + 1, finalRow);
        }
    }
    vector<int> getRow(int rowIndex) {
        std::vector<int> v1;
        std::vector<int> v2;
        pascalTriangle(v1, v2, 0, 0, rowIndex);
        return rowIndex % 2 == 0 ? v1 : v2;
    }
};
