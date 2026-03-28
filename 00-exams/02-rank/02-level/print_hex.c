/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$*/

#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = str[i] - '0' + (num * 10);
        i++;
    }
    return (num);
}

void ft_putnbr(int n)
{
    char base[16] = "0123456789abcdef";

    if (n >= 16)
        ft_putnbr(n / 16);
    write(1, &base[n % 16], 1);
}

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int num;

        num = ft_atoi(argv[1]);
        ft_putnbr(num);
    }
    write (1, "\n", 1);
}