#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
int emptyplaces = 9;

void clearBoard();
void printBoard();
bool isempty(int row, int column);
void playerMove();
void computerMove();
bool checkwinner(char winner);

int main()
{

    srand(time(NULL));

    //printf("\ncheck winner = %s\n", checkwinner(PLAYER));

    clearBoard(); 

    while (emptyplaces > 0)
    {
        printBoard();
        playerMove();
        if (checkwinner(PLAYER)) {
            printBoard();
            printf("You win!\n");
            break;
        }
        if (emptyplaces == 0) {
            printBoard();
            printf("a tie!\n");
            break;
        }
        computerMove();
        if (checkwinner(COMPUTER)) {
            printBoard();
            printf("Computer wins!\n");
            break;
        }
    }

    return 0;
}


void clearBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c\n", Board[0][0], Board[0][1], Board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", Board[1][0], Board[1][1], Board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", Board[2][0], Board[2][1], Board[2][2]);
} 

bool isempty(int row, int column)
{
    return Board[row][column] == ' ';
}

void playerMove()
{
    int playerRow, playerColumn;

    do {
        printf("insert row (1-3): ");
        scanf("%d", &playerRow);
        printf("insert column (1-3): ");
        scanf("%d", &playerColumn);

        if (playerRow < 1 || playerRow > 3 || playerColumn < 1 || playerColumn > 3) {
            printf("Invalid input. Row and column must be between 1 and 3.\n");
        } else if (!isempty(playerRow-1, playerColumn-1)) {
            printf("Case not empty, choose again.\n");
        } else {
            Board[playerRow-1][playerColumn-1] = PLAYER;
            emptyplaces--;
            break;
        }
    } while (true);

}

void computerMove()
{
    int randomrow;
    int randomcolumn;

    do {

        randomrow = rand() % 3;
        randomcolumn = rand() % 3;

    } while(!isempty(randomrow, randomcolumn));

    Board[randomrow][randomcolumn] = COMPUTER;
    emptyplaces--;
}

bool checkwinner(char winner)
{
    // rows
    for (int i = 0; i < 3; i++) 
    {
        if (Board[i][0] == winner && Board[i][1] == winner && Board[i][2] == winner) 
        {
            return true;
        }
    }
    
    // columns
    for (int j = 0; j < 3; j++) 
    {
        if (Board[0][j] == winner && Board[1][j] == winner && Board[2][j] == winner) 
        {
            return true;
        }
    }
    
    // diagonals
    if ((Board[0][0] == winner && Board[1][1] == winner && Board[2][2] == winner) || (Board[0][2] == winner && Board[1][1] == winner && Board[2][0] == winner)) 
    {
        return true;
    }
    
    return false;
}


