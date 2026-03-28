# Zero Striping
# For each zero in an mxn matrix, set its entire row and column to zero in place

def zero_striping(matrix: list[list[int]]) -> None:
    if not matrix or not matrix[0]:
        return
    m, n = len(matrix), len(matrix[0])
    zero_rows, zero_cols = set(), set()
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                zero_rows.add(i)
                zero_cols.add(j)

    for i in range(m):
        for j in range(n):
            if i in zero_rows or j in zero_cols:
                matrix[i][j] = 0

matrix = [[1, 2, 3, 4, 5],
          [6, 0, 8, 9, 10],
          [11, 12, 13, 14, 15],
          [16, 17, 18, 19, 0]]
print(matrix)
zero_striping(matrix)
print(matrix)
