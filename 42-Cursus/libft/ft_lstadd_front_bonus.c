/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:27:13 by aramos-m          #+#    #+#             */
/*   Updated: 2024/09/22 19:35:48 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list *a, b;
	a = malloc(sizeof(t_list));
	char sa[15] = "Soy la lista A";
	char sb[15] = "Soy la lista B";
	a->content = &sa;  
	b.content = &sb;
	printf("%s\n", a->content);
	ft_lstadd_front(&a, &b);
	printf("%s\n", a->content); /* a->next->content */
}