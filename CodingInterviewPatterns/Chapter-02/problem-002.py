# Verify Sudoku Board
# Given a partially completed 9x9 Sudoku board, determine if the current state of the board
# adheres to the rules of the game:
# Each row and column must contain unique numbers between 1 and 9, or be empty [0]
# Each of the nine 3x3 subgrids that compose the grid must contain unique numbers
# between 1 and 9 or be empty
# You are asked to determine whether the current state of the board is valid given
# these rules not whether the board is solvable

def verify_sudoku_board(board: list[list[int]]) -> bool:
    rows, cols = len(board), len(board[0])

    row_sets = [set() for _ in range(9)]
    col_sets = [set() for _ in range(9)]
    subgrid_sets = [[set() for _ in range(3)] for _ in range(3)]

    for r in range(9):
        for c in range(9):
            num = board[r][c]
            if num == 0:
                continue
            if num in row_sets[r]:
                return False
            if num in col_sets[c]:
                return False
            if num in subgrid_sets[r // 3][c // 3]:
                return False
            row_sets[r].add(num)
            col_sets[c].add(num)
            subgrid_sets[r // 3][c // 3].add(num)
    return True

board = [[3, 0, 6, 0, 5, 8, 4, 0, 0],
         [5, 2, 0, 0, 0, 0, 0, 0, 0],
         [0, 8, 7, 0, 0, 0, 0, 3, 1],
         [1, 0, 2, 5, 0, 0, 3, 2, 0],
         [9, 0, 0, 8, 6, 3, 0, 0, 5],
         [0, 5, 0, 0, 9, 0, 6, 0, 0],
         [0, 3, 0, 0, 0, 8, 2, 5, 0],
         [0, 1, 0, 0, 0, 0, 0, 7, 4],
         [0, 0, 5, 2, 0, 6, 0, 0, 0]]
print(board, verify_sudoku_board(board))
