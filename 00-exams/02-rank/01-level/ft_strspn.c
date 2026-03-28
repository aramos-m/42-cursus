/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stddef.h>

size_t ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (accept[j] == s[i])
            {
                i++;
                break;
            }
            j++;
        }
        if (accept[j] == '\0')
            return (i);
    }
    return (i);
}
