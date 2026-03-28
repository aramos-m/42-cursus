/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/
#include <stdio.h>

char *ft_strrev(char *str)
{
    int i;
    int j;
    char tmp;

    i = 0;
    j = 0;
    while(str[i])
        i++;
    i--; //Retrocedes una posición en la cadena para ir de '\0' a el último caracter
    while(j < i)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return (str);
}

int main (int argc, char **argv)
{
    char s[] = "hola que tal esta usted";
    printf("%s\n", ft_strrev(s));
    return (0);
}