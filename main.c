#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
int emptyplaces = 9;

void clearBoard();
void printBoard();
bool isempty(int row, int column);
void playerMove();
void computerMove();

int main()
{

    clearBoard();

    while (emptyplaces > 0)
    {
        /*
            ! when the player plays and the case is full, the computer still plays, then we go back to the player
            TODO : don't allow the computer to play unless the player plays in an empty case
        */
        printBoard();
        playerMove();
        computerMove();

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
    if (Board[row][column] == ' ') return true;
    else return false;
}

void playerMove()
{
    int playerRow, playerColumn;

    do {

        printf("insert row (1-3): ");
        scanf("%d", &playerRow);
        printf("insert column (1-3): ");
        scanf("%d", &playerColumn);

        if(isempty(playerRow-1, playerColumn-1))
        {
        Board[playerRow-1][playerColumn-1] = PLAYER;
        emptyplaces --;
        } else printf("\ncase not empty, choose again\n");

    } while ((playerRow < 1 || playerRow > 3 || playerColumn < 1 || playerColumn > 3) && !isempty(playerRow-1, playerColumn-1));

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

