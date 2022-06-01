/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_half.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:54:22 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/06 03:28:37 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	after_half(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	after_push_b(nil_a, nil_b);
	while (nil_a->size_now != nil_a->stack_size)
	{
		set_sorted_a(nil_a, nil_b);
		Qsort_b(nil_a, nil_b);
		pb_same_status(nil_a, nil_b);
	}
	return ;
}

int	after_push_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	nil_b->bmax = nil_a->sorted_rank;
	// set_sorted_a(nil_a, nil_b);
	while (nil_a->next->sorted < 1) 
	{
		set_sorted_a(nil_a, nil_b);
		if (nil_a->next->sorted != 2)
			pb (nil_a, nil_b);
		if (check_sequence(nil_a, nil_b) && nil_b->size_now > 3)
			return (1);
	}
	return (0);
}

int	check_sequence(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	long		*array;
	long		b_min;
	int			i;
	int			j;

	j = 0;
	i = 0;
	array = (long *)malloc(sizeof(long) * nil_b->size_now);
	b_min = nil_a->sorted_rank + 1;
	p = nil_b->next;
	if (nil_b->next->rank > nil_b->bmax)
		nil_b->bmax = nil_b->next->rank;
	while (p != nil_b)
	{
		array[i++] = p->rank;
		p = p->next;
	}
	asort(array, nil_b->size_now);
	i = 0;
	while (j < nil_b->size_now)
	{
		if (array[i++] == b_min)
			b_min++;
		else
		{
			free(array);
			return (0);
		}
		j++;
	}
	free(array);
	return (1);
}
