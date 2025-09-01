# Tic Tac Toe in C

This is a simple **Tic Tac Toe game** implemented in C.  
It allows two players to take turns, place their marks, and determines the winner or if the game ends in a draw.

## Features
- Two-player mode (Player 1 vs Player 2)
- Input validation for moves
- Win detection (rows, columns, diagonals)
- Draw detection
- Board display after each move

## How to Compile and Run

1. Navigate to the folder containing the code (e.g. `main.c`):
   ```bash
   cd C:\Users\Your_UserName\Documents\C
   ```

2. Compile the code with GCC:
   ```bash
   gcc main.c -o tictactoe
   ```

3. Run the game:
   ```bash
   ./tictactoe
   ```

## Example Gameplay
```
---------------------WELCOME TO MY TICTACTOE GAME---------------------
Enter Player 1's name: Alice
Enter Alice's mark: X
Enter Player 2's name: Bob
Enter Bob's mark: O
Alice's Turn
Alice (X),Enter your preferred row (0-2): 0
Alice (X),Enter your preferred column (0-2): 1
-------------
|   | X |   |
-------------
|   |   |   |
-------------
|   |   |   |
-------------
```

## File Structure
```
├── main.c        # The Tic Tac Toe source code
├── README.md     # Documentation file
```

## Author
Created by **b1aiirrr**
