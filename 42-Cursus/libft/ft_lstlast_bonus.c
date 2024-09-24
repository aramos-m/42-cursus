/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:32:10 by aramos-m          #+#    #+#             */
/*   Updated: 2024/09/24 21:08:34 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list *ft_lstlast(t_list  *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	main(void)
{
	t_list	*a, *b;
	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%s %s\n last lst: %s", b->content, b->next->content, ft_lstlast(b));
}