class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        line = set()
        row = set()
        sq = set()
        for Line in board:
            for val in Line:
                if val != '.' and val in line:
                    return False
                elif val != '.':
                    line.add(val)
            line.clear()
        
        for i in range(9):
            for j in range(9):
                if board[j][i] != '.' and board[j][i] in row:
                    return False
                elif board[j][i] != '.':
                    row.add(board[j][i])
            row.clear()
        for box_row in range(0, 9, 3):
            for box_col in range(0, 9, 3):
                sq = set()
                for i in range(3):
                    for j in range(3):
                        val = board[box_row + i][box_col + j]
                        if val != '.' and val in sq:
                            return False
                        elif val != '.':
                            sq.add(val)
            sq.clear()
        return True