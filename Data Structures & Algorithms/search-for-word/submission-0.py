from collections import deque
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board: return False
        ROW,COL = len(board),len(board[0])
        dir = [(1,0),(0,1),(-1,0),(0,-1)]
        def dfs(r,c,i):
            dir = [(1,0),(0,1),(-1,0),(0,-1)]
            if(i == len(word)): return True
            if (r < 0  or c < 0  or r >= ROW or c >= COL or word[i] != board[r][c] or board[r][c] == '#'):
                return False
            
            board[r][c] = '#'
            res = False
            for dr,dc in dir:
                nr,nc = r+dr,c+dc
                res = res or dfs(nr,nc,i+1)

            board[r][c] = word[i]
            return res


        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == word[0]:
                    if dfs(r,c,0):
                        return True
        return False


