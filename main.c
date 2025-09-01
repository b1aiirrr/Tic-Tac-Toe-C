#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int row;
    int col;
    char mark;
    char name[100];
}Player;

Player *cp,p1,p2;

char board[3][3];

void initBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void displayBoard(){
    
    printf("-------------\n");
    for(int i = 0; i < 3; i++){
        printf("| ");
       for(int j = 0; j < 3; j++){
        printf("%c | ",board[i][j]);
        }
        printf("\n");
        printf("-------------\n");
    }

}

void placeMark(int row,int col,char mark){
    if(row >= 0 && row < 3 && col >= 0 && col < 3){
        board[row][col] = mark;
    }
}

bool isValidMove(int row,int col){
    if(board[row][col] == ' ' && row >= 0 && row < 3 && col >= 0 && col < 3){
        return true;
    }
    printf("Invalid choice of row and column,TRY AGAIN!\n");
    return false;
}

void makeMove(Player *cp) {
    do {
       printf("%s (%c) Enter your preferred Row and Column (separated by space): ",cp->name,cp->mark);
       scanf("%d %d",&cp->row,&cp->col);

    } while (!isValidMove(cp->row, cp->col));

    placeMark(cp->row, cp->col, cp->mark);
}

bool checkColWin(){
    for(int i = 0; i < 3; i++){
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }
    return false;
}

bool checkRowWin(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
    }
    return false;
}

bool checkDiagWin(){
   if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]||
        board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        return true;
   }
   return false;
}

bool checkDraw(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

int main()
{
  printf("---------------------WELCOME TO MY TICTACTOE GAME---------------------\n");
 
  printf("Enter Player 1's name: ");
  scanf("%s",&p1.name);

  printf("Enter %s's mark: ",p1.name);
  scanf(" %c",&p1.mark);

  printf("Enter Player 2's name: ");
  scanf("%s",&p2.name);

  printf("Enter %s's mark: ",p2.name);
  scanf(" %c",&p2.mark);

  cp = &p1;
  initBoard();
    
    while(true){
        printf("%s's Turn\n",cp->name);
        makeMove(cp);
        displayBoard();

        if(checkColWin() || checkRowWin() || checkDiagWin()){
            printf("%s Has Won!🥳\n",cp->name);
            break;
        }
        else if(checkDraw()){
            printf("IT'S A DRAW!🤝\n");
            break;
        }
        else{
            if(cp == &p1){
                cp = &p2;
            }
            else{
                cp = &p1;
            }
        }
    }

    return 0;
}