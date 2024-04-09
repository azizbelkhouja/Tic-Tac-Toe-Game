#include <stdio.h>
#include <stdbool.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
int emptyplaces = 9;

void clearBoard();
void printBoard();
void playerMove();
bool isempty();

int main()
{

    clearBoard();
    
    printBoard();

    playerMove();

    printBoard();


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

void playerMove()
{
    int playerRow, playerColumn;

    do {
        printf("insert row (1-3): ");
        scanf("%d", &playerRow);
        printf("insert column (1-3): ");
        scanf("%d", &playerColumn);

        Board[playerRow-1][playerColumn-1] = PLAYER;
    } while (playerRow < 1 || playerRow > 3 || playerColumn < 1 || playerColumn > 3);
    
    
}

bool isempty()
{
    
}