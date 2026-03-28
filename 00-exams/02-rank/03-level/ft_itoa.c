#include <stdlib.h>
int countnumbers(int nbr)
{
    int count = 0;
    if (nbr <= 0)
    {
        count++;
        nbr*= -1;
    }
    while (nbr > 0)
    {
        nbr/=10;
        count++;
    }
    return(count);
}

char    *ft_itoa(int nbr)
{
    char* number;
    int i;
    int neg;
    
    neg = 0;
    i = countnumbers(nbr);
    number = malloc(i + 1);
    if (nbr < 0)
    {
        number[0] = '-';
        nbr*=-1;
        neg = 1;
    }
    number[i] = '\0';
    i--;
    while (i >= neg)
    {
        number[i] = (nbr % 10) + '0';
        nbr /= 10;
        i--;
    }
    return(number);
}