/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int *range;
    int size;
    int i;
    size = end - start;
    if (size < 0)
        size *= -1;
    range = malloc(sizeof(int) * (size + 1));
    i = 0;
    while (i <= size) // size es el número de veces que tiene que iterar 
    {
        if (start > end)
            range[i] = start + i;
        else
            range[i] = start - i;
        i++;
    }
    return (range);
}

int main(void)
{
    int *num;

    num = ft_range(3, 5);
    printf("%d\n", num[0]);
    return (0);
}