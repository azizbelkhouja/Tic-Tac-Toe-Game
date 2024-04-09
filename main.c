#include <stdio.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void clearBoard();
void printBoard();
void playerMove();

int main()
{

    clearBoard();
    
    printBoard();

    playerMove();


    return 0;
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

void playerMove()
{
    int place;
    do {
        printf("insert place number(1-9): ");
        scanf("%d", &place);
        switch(place) 
        {
            case 1: 
                Board[0][0] = 'X';
            break;

            case 2: 
                Board[0][1] = 'X';
            break;

            case 3: 
                Board[0][2] = 'X';
            break;

            case 4: 
                Board[1][0] = 'X';
            break;

            case 5: 
                Board[1][1] = 'X';
            break;

            case 6: 
                Board[1][2] = 'X';
            break;

            case 7: 
                Board[2][0] = 'X';
            break;

            case 8: 
                Board[2][1] = 'X';
            break;

            case 9: 
                Board[2][2] = 'X';
            break;
        }
    } while (place < 1 || place > 9);
    
}