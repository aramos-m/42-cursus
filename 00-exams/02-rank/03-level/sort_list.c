t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int sorted = 0;
    int temp;
    t_list *start = lst;
    while (sorted == 0)
    {
        lst = start;
        sorted = 1;
        while(lst->next != 0)
        {
            if (cmp(lst->data, lst->next->data) == 0)
            {
                temp = lst->data;
                lst->data = lst->next->data;
                lst->next->data =temp;
                sorted = 0;
            }
            lst = lst->next;
        }
    }
    return(start);
}