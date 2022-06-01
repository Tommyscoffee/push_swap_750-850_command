/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/05 20:25:00 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../includes/pushswap.h"

size_t	count_stack(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	is_duplicated(t_bi_list *nil, int elm)
{
	int			i;
	t_bi_list	*p;

	p = nil->next;
	i = 0;
	while (p != nil)
	{
		if (p->value == elm)
			return (TRUE);
		p = p->next;
	}
	return (FALSE);
}

int	add_list(int value, t_bi_list *nil)
{
	t_bi_list	*node;
	t_bi_list	*prev;

	if (is_duplicated(nil, value))
		ft_error();
	prev = nil->prev;
	node = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!node)
		exit(1);
	node->value = value;
	nil->prev = node;
	prev->next = node;
	node->next = nil;
	node->prev = prev;
	return (0);
}

int	check_alpha(char *str)
{
	size_t	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (!ft_isdigit((int)str[j]))
		{
			if (str[j] == '-' && ft_isdigit((int)str[j + 1]))//引数が--1の時はアルファベットと認識してエラーを吐く
				j++;
			else
			{
				printf("アルファベット エラー\n");
				exit(1);
			}
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_bi_list	*nil_a;
	t_bi_list	*nil_b;

	command_num = 0;
	nil_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	nil_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	nil_a->which = A;
	nil_b->which = B;
	init_nil(nil_a);
	init_nil(nil_b);
	nil_a->stack_size = argc - 1;
	nil_a->size_now = nil_a->stack_size;
	init_stack(argc, argv, nil_a);
	init_array(nil_a);
	operation_stack(argc, nil_a, nil_b);
	if (is_sorted(nil_a))
	{
		ft_sortdone();
	}
	ft_free(nil_a);
	ft_free(nil_b);
	system("leaks pushswap");
	return (0);
}
