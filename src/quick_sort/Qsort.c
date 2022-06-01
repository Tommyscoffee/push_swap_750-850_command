/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/02/06 03:25:03 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	unsort_set_operation(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int			tmp;

	tmp = nil_b->next->rank;
	if (nil_a->awant == 0)
		nil_a->awant = tmp;
	else if (nil_b->next->rank <= nil_a->awant)
		nil_a->awant = nil_b->next->rank - 1;
	nil_b->next->status = nil_b->pivot;
	pa(nil_a, nil_b);
	return ;
}

int	Qsort_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int			b_max;
	int			after_size;

	b_max = nil_a->pivot;
	while (nil_b->size_now > 3)
	{
		set_sorted_a(nil_a, nil_b);//追加
		nil_b->pivot = make_pivot_b(nil_a, nil_b);
		after_size = make_after_size_b(nil_a, nil_b);
		while (nil_b->size_now > after_size)
		{
			// set_sorted_a(nil_a, nil_b);//追加
			if (nil_b->next->rank > nil_b->pivot)
				unsort_set_operation(nil_a, nil_b);
			else
			{
				if (is_a_want(nil_a, nil_b))
					break ;
				else
					rb(nil_b);
			}
		}
	}
	bottom_order(nil_a, nil_b);
	set_sorted_a(nil_a, nil_b);
	return (0);
}

int	pb_same_status(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			std_status;
	int			flag;

	flag = 0;
	p = nil_a->next;
	std_status = p->status;
	if (std_status == 0)
		return (0);
	while (p->status == std_status && p->rank > 1)
	{
		if (p->rank == nil_a->sorted_rank + 1)
			set_sorted_a(nil_a, nil_b);
		else
		{
			p->status = 0;
			pb(nil_a, nil_b);
		}
		p = nil_a->next;
	}
	return (0);
}

int	Qsort(t_bi_list *nil_a, t_bi_list *nil_b)
{
	size_t		i;

	i = 0;
	push_half_a(nil_a, nil_b);
	while (nil_a->size_now != nil_a->stack_size)
	{
		// set_sorted_a(nil_a, nil_b);//追加
		Qsort_b(nil_a, nil_b);
		pb_same_status(nil_a, nil_b);
	}
	while (!is_sorted(nil_a))
		after_half(nil_a, nil_b);
	return (0);
}
