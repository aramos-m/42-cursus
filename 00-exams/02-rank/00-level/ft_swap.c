/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int a = 0;
    int b = 2;
    printf("A = %d, B = %d\n", a, b);
    ft_swap(&a, &b);
    printf("A = %d, B = %d\n", a, b);
    return (0);
}