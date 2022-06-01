/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:48:46 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/05 20:41:32 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	reset_stack_a(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->prev;
	if (nil_a->sorted_rank > 0)
	{
		while (p->rank != nil_a->sorted_rank)
		{
			rra(nil_a);
			p = nil_a->prev;
		}
	}
	return ;
}

int	push_half_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	size_t		i;
	int			after_a_size;

	i = 0;
	nil_a->pivot = make_pivot_a(nil_a, nil_b);
	after_a_size = make_after_size_a(nil_a, nil_b);
	while (nil_a->size_now > (after_a_size + nil_a->sorted_rank))
	{
		if (nil_a->next->rank <= nil_a->pivot
			&& nil_a->next->rank > nil_a->sorted_rank)
		{
			if (nil_a->next->sorted != 2)
			{
				pb(nil_a, nil_b);
				is_b_want(nil_a, nil_b);
			}
		}
		if (nil_a->next->rank > nil_a->pivot && nil_a->size_now > after_a_size)
			ra(nil_a);
		if (is_sorted(nil_a))
			exit(0);
		i++;
	}
	reset_stack_a(nil_a);
	return (0);
}

int	push_half_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;
	int			start_size;

	start_size = nil_b->size_now;
	i = 0;
	p = nil_b->next;
	while (nil_a->size_now > (start_size / 2) + nil_a->sorted_rank)
	{
		set_sorted_a(nil_a, nil_b);
		if (p->rank <= nil_a->pivot)
		{
			pb(nil_a, nil_b);
			// printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);
		}
		if (nil_a->next->rank > nil_a->pivot
			&& nil_a->size_now > ((nil_a->stack_size) / 2))
			ra(nil_a);
		p = nil_a->next;//これをやらないとpはスタックbにいくので,
	}
	return (0);
}