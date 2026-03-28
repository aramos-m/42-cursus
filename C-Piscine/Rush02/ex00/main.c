/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bquilumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:56:45 by bquilumb          #+#    #+#             */
/*   Updated: 2023/08/27 21:34:55 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush02(char *dic_name, char *str_number);
int		ft_atoi(char *str_number);
int		check_dic(char *dic_name, char *dic);
void	show_number(int number, char *dic);
int		ft_strlen(char *str);
char	*search_nb(char *str, char *to_find);
void	search_value(char *aux_str, char *aux_tf, int is_prefix, int *occurs);
int		is_value(char c);
int		*entry(int num);
char	*put_str(int number);

int	main(int argc, char *argv[])
{
	if (argc == 2)
		rush02("numbers.dict", argv[1]);
	else if (argc == 3)
		rush02(argv[1], argv[2]);
	else
		write(1, "Error\n", 6);
	return (0);
}

void	rush02(char *dic_name, char *str_number)
{
	int		number;	
	char	*dic;
	int		*entries;

	number = ft_atoi(str_number);
	dic = (char *) malloc(1000 * sizeof(char));
	if (number != -1)
	{
		if (check_dic(dic_name, dic) != -1)
		{
			entries = entry(number);
			while (*entries != -1)
			{
				show_number(*entries, dic);
				if (*(entries + 1) != -1)
					write(1, " ", 1);
				entries ++;
			}
		}
		else
			write(1, "Dict Error\n", 11);
	}
	free(dic);
}

void	show_number(int number, char *dic)
{
	char	*aux_dic;
	int		started;
	int		i;
	char	*str_number;

	aux_dic = dic;
	started = 0;
	i = 0;
	str_number = put_str(number);
	aux_dic = search_nb(aux_dic, str_number);
	free(str_number);
	while (*aux_dic != '\n')
	{
		if (started)
		{	
			write(1, aux_dic, 1);
			i ++;
		}
		else
		{
			if (is_value(*(aux_dic + 1)))
				started = 1;
		}
		aux_dic ++;
	}
}

char	*search_nb(char *str, char *to_find)
{
	char	*pointer;
	char	*aux_str;
	char	*aux_tf;
	int		occurs;
	int		is_prefix;

	pointer = NULL;
	while (*str != '\0' && pointer != str)
	{
		aux_str = str;
		aux_tf = to_find;
		occurs = 1;
		is_prefix = 1;
		if (*str == '\n')
			is_prefix = 1;
		if (is_prefix && is_value(*str))
			occurs = 0;
		search_value(aux_str, aux_tf, is_prefix, &occurs);
		if (occurs == 1 && is_prefix)
			pointer = str;
		else
			str ++;
	}
	return (pointer);
}

void	search_value(char *aux_str, char *aux_tf, int is_prefix, int *occurs)
{
	while (*aux_tf != '\0' && *occurs == 1 && is_prefix)
	{
		if (*aux_tf != *aux_str)
			*occurs = 0;
		aux_tf ++;
		aux_str ++;
	}
}
/*
int	exist_prefixs(int *entries, char *dic)
{
	int		exist;
	char	*aux_dic;
	int		*aux_entries;

	exist = 1;
	aux_dic = dic;
	aux_entries = entries;
	while(*aux_entries != -1 && exist)
	{
		if (search_nb(aux_dic, put_str(*aux_entries)) != NULL)
			aux_entries ++;
		else
			exist = 0;
	}
	return (exist);
}*/
