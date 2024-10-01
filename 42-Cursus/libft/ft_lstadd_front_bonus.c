/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:37:21 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:42:44 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*a;
	t_list	b;

	a = malloc(sizeof(t_list));
	char sa[15] = "Soy la lista A";
	char sb[15] = "Soy la lista B";

	a->content = &sa;  
	b.content = &sb;
	printf("%s\n", a->content);
	ft_lstadd_front(&a, &b);
	printf("%s\n", a->content);
}*/