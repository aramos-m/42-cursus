/*Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>
```

##Explicación del enunciado
La función flood_fill debe hacer lo siguiente:

Recibe tres parámetros:
- char **tab: Un array bidimensional de caracteres (la "zona" a rellenar).
- t_point size: Las dimensiones del array (ancho y alto).
- t_point begin: El punto de inicio para el relleno.

A partir del punto de inicio (begin), debe reemplazar todos los caracteres conectados que sean iguales al carácter inicial con el carácter 'F'.

La conexión entre caracteres se considera solo horizontal y verticalmente, no en diagonal.

El relleno debe detenerse cuando encuentre un carácter diferente o los límites del array.

En esencia, simula el comportamiento de la herramienta "bote de pintura" en programas de dibujo, rellenando una zona contigua del mismo color (en este caso, del mismo carácter).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;


void fill(char **tab, t_point size, t_point pos, char c)
{
    t_point new;
    printf("HOLA FILL %d %d \n", pos.x, pos.y) ;
    tab[pos.y][pos.x] = 'F';
    printf("HOLA FILL %d %d POS %c \n", pos.x, pos.y, tab[pos.y][pos.x]) ;
    new = pos;
    if (pos.y > 0 && (tab[pos.y - 1][pos.x] == c))
    {
        new.y--;
        fill(tab, size, new, c);
    }
    if (pos.y < size.y - 1 && (tab[pos.y + 1][pos.x] == c))
    {
        new.y++;
        fill(tab, size, new, c);
    }
    if (pos.x > 0 && (tab[pos.y][pos.x - 1] == c))
    {
        new.x--;
        fill(tab, size, new, c);
    }
    if (pos.x < size.x - 1 && (tab[pos.y][pos.x + 1] == c))
    {
        new.x++;
        fill(tab, size, new, c);
    }
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char start_char;

    if (begin.x > size.x || begin.y > size.y)
        return ;
    start_char = tab[begin.x][begin.y];
    fill(tab, size, begin, start_char);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
    int y;

    y = 0;
	t_point size = {8, 5};
	char *zone[8] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
    char**  area = make_area(zone, size);
    t_point begin = {0, 3};
    flood_fill(area, size, begin);
    while (y < 5)
    {
        printf("%s\n", area[y]);
        y++;
    }
}