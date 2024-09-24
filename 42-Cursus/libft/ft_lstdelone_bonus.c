/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:09:36 by aramos-m          #+#    #+#             */
/*   Updated: 2024/09/24 21:29:41 by aramos-m         ###   ########.fr       */
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

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

int	main(void)
{
	t_list	*a;
	char	*cont;

	cont = malloc(4);
	cont[0] = 'A';
	cont[1] = 'n';
	cont[2] = 'a';
	cont[3] = 0;
	a = ft_lstnew(cont);
	printf("%s\n", cont);
	ft_lstdelone(a, free);
	printf("%s\n", cont);
}