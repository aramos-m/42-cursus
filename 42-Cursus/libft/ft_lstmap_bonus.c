/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:24:45 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 22:34:09 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;

	if (!lst)
		return (NULL);
	flst = malloc(sizeof(t_list));
	if (!flst)
		free (flst);
	flst->content = f(lst->content);
	flst->next = ft_lstmap(lst->next, f, del);
	return (flst);
}

void	*ft_double(void *number)
{
	int	*num1;
	int	*num2;

	num1 = (int *)number;
	num2 = malloc(sizeof(int) * 1);
	*num2 = *num1 + *num1;
	return ((void *)num2);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*result;
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
	result = ft_lstmap(a, (void *)(ft_double), free);
	printf("%d %d\n", *(int *)result->content, *(int *)result->next->content);
}