/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:50:28 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:51:52 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	if (!last_node)
		return ;
	last_node->next = new;
}

/*int main(void)
{
	t_list	*a;
	t_list	*b;
	
	a = ft_lstnew("Soy");
	b = ft_lstnew("Ana");
	ft_lstadd_back(&a, b);
	printf("%s %s", a->content, a->next->content);
}*/