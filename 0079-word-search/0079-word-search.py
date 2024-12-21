class Solution(object):
    def __init__(self):
        self.ROWS = 0
        self.COLS = 0
        self.boardCopy = []

    def backtrack(self, row, col, word, index):
        if index >= len(word): 
            return True
        if row < 0 or row == self.ROWS or col < 0 or col == self.COLS or self.boardCopy[row][col] != word[index]:
            return False
        self.boardCopy[row][col] = '#'
        rowOffset = [0,1,0,-1]
        colOffset = [1,0,-1,0]

        for i in range(4):
            result = self.backtrack(row+rowOffset[i], col+colOffset[i], word, index+1)
            if result:
                return True
        self.boardCopy[row][col] = word[index]
        return False 
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.boardCopy = board
        self.ROWS = len(board)
        self.COLS = len(board[0])

        for row in range(self.ROWS):
            for col in range(self.COLS):
                if self.backtrack(row, col, word, 0):
                    return True
        return False