# Zero Striping
# For each zero in an mxn matrix, set its entire row and column to zero in place

def zero_striping(matrix: list[list[int]]) -> None:
    if not matrix or not matrix[0]:
        return
    m, n = len(matrix), len(matrix[0])
    first_row_has_zero = False
    for c in range(n):
        if matrix[0][c] == 0:
            first_row_has_zero = True
            break

    first_col_has_zero = False
    for r in range(m):
        if matrix[r][0] == 0:
            first_col_has_zero = True
            break

    # Use the first row and column as markers
    for r in range(1, m):
        for c in range(1, n):
            if matrix[r][c] == 0:
                matrix[r][0] = 0
                matrix[0][c] = 0

    # Update the submatrix
    for r in range(1, m):
        for c in range(1, n):
            if matrix[r][0] == 0 or matrix[0][c] == 0:
                matrix[r][c] = 0

    if first_row_has_zero:
        for c in range(n):
            matrix[0][c] = 0

    if first_col_has_zero:
        for r in range(m):
            matrix[r][0] = 0


matrix = [[1, 2, 3, 4, 5],
          [6, 0, 8, 9, 10],
          [11, 12, 13, 14, 15],
          [16, 17, 18, 19, 0]]
print(matrix)
zero_striping(matrix)
print(matrix)
