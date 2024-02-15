class GameEntry:
    """Represents one entry of a list of high scores."""
    
    def __init__(self, name="", score=0):
        self.name = name
        self.score = score

    def getName(self):
        return self.name

    def getScore(self):
        return self.score

    def __str__(self):
        return f"({self.name}, {self.score})"


class Scores:
    """Fixed-length sequence of high scores in nondecreasing order."""
    
    def __init__(self, capacity=10):
        self.board = [None] * capacity
        self.n = 0

    def add(self, entry):
        if self.n < len(self.board) or entry.getScore() > self.board[-1].getScore():
            if self.n < len(self.board):
                self.n += 1
            
            j = self.n - 1
            while j > 0 and self.board[j-1].getScore() < entry.getScore():
                self.board[j] = self.board[j-1]
                j -= 1
            self.board[j] = entry

    def remove(self, index):
        if index < 0 or index >= self.n or self.board[index] is None:
            raise IndexError("Invalid index")
        
        removed_entry = self.board[index]
        for j in range(index, self.n - 1):
            self.board[j] = self.board[j+1]
        self.board[self.n - 1] = None
        self.n -= 1
        return removed_entry

    def __str__(self):
        return "\n".join(str(self.board[j]) for j in range(self.n) if self.board[j] is not None)


# Demo
if __name__ == "__main__":
    scores = Scores(capacity=5)
    scores.add(GameEntry("Alice", 110))
    scores.add(GameEntry("Bob", 150))
    scores.add(GameEntry("Cindy", 120))

    print("High scores:")
    print(scores)

    print("\nRemoving score at index 1 (Cindy's score):")
    scores.remove(1)
    print(scores)
