/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:45:52 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:47:31 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%s %s\n last lst: %s", b->content, b->next->content, ft_lstlast(b));
}*/