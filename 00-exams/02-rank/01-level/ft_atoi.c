/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    if (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = str[i] - '0' + (num * 10);
        i++;
    }
    return (sign * num);
}

int main (int argc, char **argv)
{
    printf("%d\n", ft_atoi(argv[1]));
    return (0);
}
