/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:58:20 by akihito           #+#    #+#             */
/*   Updated: 2022/02/05 20:27:04 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	init_nil(t_bi_list *nil)
{
	nil->next = nil;
	nil->prev = nil;
	nil->value = -1;
	nil->rank = -1;
	nil->pivot = 0;
	nil->stack_size = 0;
	nil->status = 0;
	nil->size_now = 0;
	nil->awant = 1;
	return ;
}

void	asort(long *a, int idx)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < idx)
	{
		j = i + 1;
		while (j < idx)
		{
			tmp = 0;
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	init_rank(t_bi_list *nil, long *sorted)
{
	t_bi_list	*p;
	size_t		i;
	size_t		j;

	p = nil->next;
	i = 0;
	j = 0;
	while (p != nil)
	{
		i = 0;
		while (i < nil->stack_size)
		{
			if (p->value == sorted[i])
			{
				p->rank = i + 1;
				break ;
			}
			i++;
		}
		p = p->next;
	}
	return (0);
}

int	init_array(t_bi_list *nil_a)
{
	t_bi_list	*p;
	long		*array;
	long		i;

	array = (long *)malloc(sizeof(long) * nil_a->stack_size);
	i = 0;
	p = nil_a->next;
	while (p != nil_a)
	{
		array[i++] = p->value;
		p = p->next;
	}
	asort(array, nil_a->stack_size);
	if (init_rank(nil_a, array))
		return (TRUE);
	free(array);
	return (0);
}

int	init_stack(int argc, char **argv, t_bi_list *nil)
{
	size_t		i;
	size_t		j;
	long		value;
	nil->sorted_rank = 0;
	i = 1;
	j = 1;

	while (i < argc)
	{
		check_alpha(argv[i]);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_error();
		}
		if (add_list(value, nil))
		{
			ft_error();
		}
		i++;
	}
	return (0);
}
