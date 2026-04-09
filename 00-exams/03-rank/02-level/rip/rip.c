#include<stdio.h>
#include<unistd.h>

//Devuelve la diferencia entre parentesis abiertos y cerrados, si el numero es positivo hay más abiertos, si es negativo hay más cerrados
int countparenthesis(char *string)
{
    int count = 0;
    int i;
    while (string[i] != 0)
    {
        if (string[i] == '(')
            count++;
        else if(string[i] == ')')
            count--;
        i++;
    }
    return(count);
}

void printparenthesis(char *string, int dif, int i)
{
    if (dif == 0)
    {
        printf("%s\n", string);
        return ;
    }
    if (dif < 0)
    {
        if (string[i] == ')')
        {
            string[i] = ' ';
            printparenthesis(string, (dif + 1), i + 1);
            string[i] = ')';
            printparenthesis(string, dif, i + 1);
        }
        else if (string[i] != 0)
            printparenthesis(string, dif, i + 1);
    }
    else if (dif > 0)
    {
        if (string[i] == '(')
        {
            string[i] = ' ';
            printparenthesis(string, (dif - 1), i + 1);
            string[i] = '(';
            printparenthesis(string, dif, i + 1);
        }
        else if (string[i] != 0)
            printparenthesis(string, dif, i + 1);
    }

}

int main(int argc, char **argv)
{
    int count;

    count = countparenthesis(argv[1]);
    printf("%d\n", count);
    printparenthesis(argv[1], count, 0);
}