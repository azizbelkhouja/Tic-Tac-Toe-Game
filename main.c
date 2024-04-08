#include <stdio.h>

char Board[3][3];

void clearBoard();
void printBoard();

int main()
{
    clearBoard();
    printBoard();
}
void clearBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        Board[i][j] = ' ';
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