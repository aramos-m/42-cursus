#include <stdio.h>
#include <stdlib.h>
int countwords(char *str)
{
    int i = 0;
    int words = 0;
    int newword;
    while(str[i] != 0)
    {
        while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != 0)
            i++;
        newword = 0;
        while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != 0)
        {
            if (newword == 0)
            {   
                newword = 1;
                words++;
            }
            i++;
        }
    }
    return(words);
}

int sizeofword(char *str)
{
    static int i; // Para que no empiece a buscar palabras desde el principio de la cadena sino dede la última en la que se quedó
    int startword;
    while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != 0)
        i++;
    startword = i;
    while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != 0)
    {
        i++;
    }
    return(i - startword);
}

void fillwords(char *str, char **split, int words)
{
    int i = 0;
    int j = 0;
    int word = 0;
    while(word < words)
    {
        while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != 0)
            i++;
        j = 0;
        while (str[i] != 0 && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        {
            split[word][j] = str[i];
            i++;
            j++;
        }
        split[word][j] = 0;
        word++;
    }
    split[word] = 0;
}

char    **ft_split(char *str)
{
    int i = 0;
    char **split;
    int words = countwords(str);
    split = malloc(sizeof(char *) * (words + 1));
    while (i < words)
    {   
        split[i] = malloc(sizeofword(str) + 1);
        i++;
    }
    fillwords(str, split, words);
    return(split);
}