/*Asignación: expand_str

Este programa toma una cadena como argumento y la muestra con exactamente tres
espacios entre cada palabra, sin espacios ni tabulaciones al principio o al final,
seguido de un salto de línea.

Una "palabra" se define como una sección de la cadena delimitada por espacios/tabulaciones,
o por el inicio/fin de la cadena.

Si el número de parámetros no es 1, o si no hay palabras, simplemente se muestra
un salto de línea.

Ejemplos:
./expand_str "See? It's easy to print the same thing"
See?   It's   easy   to   print   the   same   thing

./expand_str " this        time it      will     be    more complex  "
this   time   it   will   be   more   complex

./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..."
(muestra solo un salto de línea)

./expand_str ""
(muestra solo un salto de línea)
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int word_start;

    i = 0;
    word_start = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            while ((argv[1][i] != ' ' && argv[1][i] != '\t') && argv[1][i] != '\0') // Para controlar el final de cadena
            {
                write(1, &argv[1][i], 1);
                word_start = 1;
                i++;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t') // Quitar espacios iniciales
                i++;
            if (word_start && argv[1][i] != '\0') // Para que no imprima espacio ni al principio ni al final
                write(1, "   ", 3);  
        }
    }
    write(1, "\n", 1);
}