/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$*/

#include <stdio.h>

int ft_atoi(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while(str[i] >= '0'&& str[i] <= '9')
    {
        num = str[i] - '0' + (num * 10);
        i++;
    }
    return (num);
}

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        int a;
        int b;
        int mayor;
        int minor;
        int i;

        a = ft_atoi(argv[1]);
        b = ft_atoi(argv[2]);

        if (a > b)
        {
            mayor = a;
            minor = b;
        }
        else
        {
            mayor = b;
            minor = a;
        }
        i = minor;
        while (mayor % i != 0 || minor % i != 0)
            i--;
        printf("%d", i);
    }
    printf("\n");
}