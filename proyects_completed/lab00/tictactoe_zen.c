#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

#define CELL_MAX ((SIZE * SIZE) - 1)
#define SIZE 4

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[SIZE][SIZE])
{
    int cell = 0;

    print_sep(SIZE);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}

char get_winner(char board[SIZE][SIZE])
{
    char winner = '-';
    int f;
    int c;
    f = 0;
    c = 0;
    bool fila;
    fila = true;
    bool colu;
    colu = true;
    bool diago_uno;
    diago_uno = true;
    bool diago_dos;
    diago_dos = true;

    /*Filas*/
    while (f < SIZE)
    {
        c = 0;
        while (c < (SIZE - 2))
        {
            
            fila = fila && (board[f][c] != '-') && (board[f][c] == board[f][c+1]) && (board[f][c+1] == board[f][c+2]);
            c = c + 1;
        }
        if (fila == true)
        {
            winner = board[f][c-1];
        }
        f = f+1;
    }
    
    f = 0;
    c = 0;

    /*Columnas*/
    while (c < SIZE)
    {
        f = 0;
        while (f < (SIZE - 2))
        {
            colu = colu && (board[f][c] != '-') && (board[f][c] == board[f+1][c]) && (board[f+1][c] == board[f+2][c]);
            f = f + 1;
        }
        if (colu == true)
        {
            winner = board[f-1][c];
        }
        c = c+1;
    }
    

    f = 0;
    c = 0;

    /*Diagonales*/

    while (c < (SIZE - 2))
    {
        diago_uno = diago_uno && (board[c][c] != '-') && (board[c][c] == board[c+1][c+1]) && (board[c+1][c+1] == board[c+2][c+2]);
        diago_dos = diago_dos && (board[SIZE-1][SIZE-1] != '-') && (board[SIZE-1-c][SIZE-1-c] == board[SIZE - 2 - c][SIZE - 2 - c]) && (board[SIZE - 2 - c][SIZE - 2 - c] == board[SIZE - 3 - c][SIZE - 3 - c]);
        c = c+1;
    }
    if (diago_uno == true)
    {
        winner = board[0][0];
    }
    else if (diago_dos == true)
    {
        winner = board[SIZE-1][SIZE-1];
    }

    return winner;
}

bool has_free_cell(char board[SIZE][SIZE])
{
    bool free_cell=false;
    char aux;
    
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            aux = board[r][c];
            if (aux == '-')
            {
                free_cell=true;
            }
            
        }
        
    }
    
    return free_cell;
}

int main(void)
{
    printf("TicTacToe \n");

    /*
    char board[SIZE][SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };
    */

   char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
        board[i][j] = '-';
    }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / SIZE;
            int colum = cell % SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
