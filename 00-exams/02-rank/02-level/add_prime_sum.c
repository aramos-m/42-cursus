/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

int ft_atoi (char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = str[i] - '0' + (num * 10);
        i++;
    }
    return (num);
}

void ft_putnbr(int num)
{
    char    c;

    if (num >= 10)
        ft_putnbr(num / 10);
    c = num % 10 + '0';
    write(1, &c, 1);
}

// Todos los números son divisibles entre 1
int main (int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '-')
    {
        int num;
        int i;
        int j;
        int sum;

        num = ft_atoi(argv[1]);
        i = 2;
        sum = 0;
        while (i <= num)
        {
            j = 2;
            while (j <= i)
            {
                if (j == i)
                    sum += j;
                else if (i % j == 0)
                    break;
                j++;
            }
            i++;
        }
        ft_putnbr(sum);
    }
    else
        ft_putnbr(0);
    write(1, "\n", 1);
}