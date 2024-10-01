/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:53:18 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 21:57:13 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	f(lst->content);
	ft_lstiter(lst->next, f);
}

/*void ft_double(void  *string)
{
	int * num;

	num = (int *)string;
	*num += *num;
	return ;
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	int		*num1;
	int		*num2;

	num1 = malloc (sizeof(int) * 1);
	num2 = malloc (sizeof(int) * 1);

	*num1 = 7;
	*num2 = 2;
	printf("%d\n", *num1);
	a = ft_lstnew(num1);
	b = ft_lstnew(num2);
	ft_lstadd_back(&a, b);
	printf("%d %d\n", (*(int *)(a->content)), *(int *)a->next->content);
	ft_lstiter(a, (void *)(ft_double));
	printf("%d %d\n", *(int *)a->content, *(int *)a->next->content);
}*/