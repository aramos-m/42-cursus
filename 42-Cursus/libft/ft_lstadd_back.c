/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:20:40 by aramos-m          #+#    #+#             */
/*   Updated: 2024/09/24 21:08:02 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list *ft_lstlast(t_list  *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list  *last_node;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		return ;
	last_node->next = new;
}

int main(void)
{
	t_list *a, *b;
	a = ft_lstnew("Soy");
	b = ft_lstnew("Ana");
	ft_lstadd_back(&a, b);
	printf("%s %s", a->content, a->next->content);
}