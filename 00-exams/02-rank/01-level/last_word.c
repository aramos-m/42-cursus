/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i;
        int j;
        
        i = 0;
        j = 0;
        while(argv[1][i])
        {
            if (argv[1][i] == ' ' && (argv[1][i + 1] > 32 && argv[1][i + 1] < 127))
                j = i + 1;
            i++;
        }
        while(argv[1][j])
        {
            if ((argv[1][j] > 32 && argv[1][j] < 127))
                write(1, &argv[1][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
}

/*int main(int argc, char **argv)
{
    int i = 0;
    int j;
    while (argv[1][i])
    {
        i++;
    }
    while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i > 0) // Desrecorres para quitar los espacios del final
        i--;
    while (argv[1][i] != ' ' && argv[1][i] != '\t' && i >0)
        i--;
    while (argv[1][i] != ' ' && argv[1][i] != '\t' && i >0)
    {  
        i++;
        write(1, &argv[1][i], 1);

    } 
}*/
