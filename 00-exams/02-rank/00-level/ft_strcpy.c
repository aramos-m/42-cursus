/*# ft_strcpy
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main(void)
{
    char src[] = "1111111111111111111111111";
    char dst[] = "0000000000000000000000000";
    printf("original: %s\n", strcpy(dst, src));
    printf("mystrcpy: %s\n", ft_strcpy(dst, src));
    return (0);
}