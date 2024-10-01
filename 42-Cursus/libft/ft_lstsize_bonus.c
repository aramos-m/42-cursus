/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:37:03 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:45:18 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

/*int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%s %s\n %d\n", b->content, b->next->content, ft_lstsize(a));
}*/