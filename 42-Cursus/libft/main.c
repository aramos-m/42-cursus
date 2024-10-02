#include "libft.h"

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