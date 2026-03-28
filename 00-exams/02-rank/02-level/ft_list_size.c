/*Asignación: ft_list_size

Esta función devuelve el número de elementos en la lista enlazada
que se le pasa como argumento.

La función debe declararse de la siguiente manera:
int ft_list_size(t_list *begin_list);

Utilizamos la estructura t_list definida en ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include "list.h"

int ft_list_size(t_list *begin_list)
{
    int count;

    count = 0;
    while (begin_list)
    {
        count ++;
        begin_list = begin_list->next;
    }
    return (count);
}