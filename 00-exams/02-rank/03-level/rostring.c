/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        int i;
        int first_word_start;
        int first_word_end;
        int first_space;

        i = 0;
        while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0')
            i++;
        first_word_start = i;
        while ((argv[1][i] != ' ' && argv[1][i] != '\t') && argv[1][i] != '\0')
            i++;
        first_word_end = i;
        first_space = 1; // Se inicializa a uno para que no imprima un espacio al inicio de la primera palabra (primera iteración)
        while (argv[1][i])
        {
            while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0')
            {
                if (first_space == 0)
                {
                    write(1, " ", 1);
                    first_space = 1;
                }
                i++;
            }
            while ((argv[1][i] != ' ' && argv[1][i] != '\t') && argv[1][i] != '\0')
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            first_space = 0;
        }
        if (argv[1][i -1] != ' ' && i != first_workd_size) // Para saber si solo hay una palabra
            write(1, " ", 1);
        write(1, &argv[1][first_word], first_workd_size - first_word);
    }
    write (1, "\n", 1);
}

