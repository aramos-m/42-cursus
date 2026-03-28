/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

// IGUAL QUE FT_STRCSPN
#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s2[j] == s1[i])
                return ((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int main (int argc, char **argv)
{
    printf("%s\n", ft_strpbrk(argv[1], argv[2]));
    return (0);
}
