// Assignement name : n_queens

// Expected files : *.c *.h

// Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr

// -------------------------------------------------------------------------

// Write a program that will print all the solutions to the n queens problem
// for a n given as argument.
// We will not test with negative values.
// The order of the solutions is not important.

// You will display the solutions under the following format :
// <p1> <p2> <p3> ... \n
// where pn are the line index of the queen in each colum starting from 0.

// For example this should work :
// $> ./n_queens 2 | cat -e

// $> ./n_queens 4 | cat -e
// 1 3 0 2$
// 2 0 3 1$

// $> ./n_queens 7 | cat -e
// 0 2 4 6 1 3 5$
// 0 3 6 2 5 1 4$
// etc...      


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

// Retorna 1 si la posicion no es valida para colocar a la reina y 0 si lo es.
int checkisvalid(int line, int *board)
{
    int queen = board[line]; // Copio la posicion de la reina actual y reduzco para comprobar las anteriores reinas
    int iter = 1 ;
    while (line >= iter)
    {
        if (board[line - iter] == queen)
            return (1);
        if ((board[line - iter] == (queen - iter)) || board[line - iter] == (queen + iter))
            return (1);
        iter++;
    }
    return (0);
}

int printresult(int *board, int size)
{
    int iter = 0;
    while(iter < size)
    {
        fprintf(stdout, "%d", board[iter++]);
        if (iter < size)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}

int main(int argc, char **argv)
{
    if(argc != 2)
        return (1);
    
    int size = atoi(argv[1]);
    int board[size];

    memset(board, -1, size * sizeof(int)); // Inicializamos el tablero con -1 (sin reina)

    int iter = 0;
    while(iter < size)
    {
        board[iter]++;
        if (board[iter] >= (size)) // Si no es valida y ya esta en la ultima posicion del tablero saca a la reina y vuelve a la fila anterior
        {
            if (iter == 0) // Si la reina que se sale es la de la primera fila es porque no quedan soluciones posibles y nos salimos del programa
                return(0);
            board[iter] = -1;
            iter--;
        }
        else if(checkisvalid(iter, board) == 0)
        {
            if (iter == size - 1)
            {
                printresult(board,size);
                board[iter] = -1; 
                iter--;
            }
            else
                iter++; // Solo si es valida avanza a la siguiente fila
        }
    }
}