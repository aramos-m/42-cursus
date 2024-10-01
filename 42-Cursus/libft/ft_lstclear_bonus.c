/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:27:20 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:54:42 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!*lst)
		return ;
	ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

/*int	main(void)
{
	t_list	*a;
	t_list	*b;
	char	*cont;
	char	*cont2;

	cont = malloc(4);
	cont[0] = 'A';
	cont[1] = 'n';
	cont[2] = 'a';
	cont[3] = 0;
	cont2 = malloc(4);
	cont2[0] = 'A';
	cont2[1] = 'n';
	cont2[2] = 'a';
	cont2[3] = 0;
	a = ft_lstnew(cont);
	b = ft_lstnew(cont2);
	a->next = b;
	printf("%p\n %p\n", a, a->next);
	ft_lstclear(&a, free);
	printf("%p\n %p\n", a, b->content);
}*/
