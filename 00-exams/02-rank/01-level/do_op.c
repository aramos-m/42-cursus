/*Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

#include <stdio.h>

int ft_atoi(const char *str)
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
            sign += -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = str[i] - '0' + (num * 10);
        i++;
    }
    return (sign * num);
}

int main(int argc, char **argv)
{
    if (argc == 4 && !argv[2][1])
    {
        int operando1;
        int operando2;

        operando1 = ft_atoi(argv[1]);
        operando2 = ft_atoi(argv[3]);
        if (argv[2][0] == '+')
            printf("%d", operando1 + operando2);
        if (argv[2][0] == '-')
            printf("%d", operando1 - operando2);
        if (argv[2][0] == '*')
            printf("%d", operando1 * operando2);
        if (argv[2][0] == '/') 
            printf("%d", operando1 / operando2);
        if (argv[2][0] == '%')
            printf("%d", operando1 % operando2);
    }
    printf("\n");
}
