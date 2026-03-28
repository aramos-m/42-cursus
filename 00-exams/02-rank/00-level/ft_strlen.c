/*# ft_strlen
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

#include <string.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int main(void)
{
    char str[] = "Hola me llamo Ana";
    printf("strlen: %ld\n", strlen(str));
    printf("mystrlen: %d\n", ft_strlen(str));
    return (0);
}