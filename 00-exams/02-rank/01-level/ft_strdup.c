/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
    int i;
    char *dup;

    i = 0;
    while (src[i])
        i++;
    dup = malloc(i + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while(src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup); 
}

int main (int argc, char **argv)
{
    printf("%s\n", ft_strdup(argv[1]));
    return (0);
}