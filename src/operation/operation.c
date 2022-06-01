/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:12 by akihito           #+#    #+#             */
/*   Updated: 2022/01/19 20:47:54 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
// 3個の引数は２個以内のアクションで納める。

int	arg_2(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (nil->which == A)
	{
		if (p->rank > p->next->rank)
		{
			sa(nil);
			return (0);
		}
	}
	else
	{
		if (p->rank < p->next->rank)
		{
			sb(nil);
			return (0);
		}
	}
	return (0);
}

int	arg_5(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int			i;

	i = 0;
	while (nil_a->size_now > 3)
	{
		if (nil_a->next->rank == 1 || nil_a->next->rank == 2)
		{
			pb(nil_a, nil_b);
		}
		else if (nil_a->prev->rank == 1 || nil_a->prev->rank == 2)
		{
			rra(nil_a);
			pb(nil_a, nil_b);
		}
		else
			ra(nil_a);
		i++;
	}
	arg_3(nil_a);
	arg_2(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return (0);
}

int	arg_6(t_bi_list *nil_a, t_bi_list *nil_b)
{
	size_t			i;

	i = 0;
	while (i < nil_a->stack_size)
	{
		if (nil_a->next->rank == 1 || nil_a->next->rank == 2
			|| nil_a->next->rank == 3)
		{
			pb(nil_a, nil_b);
		}
		else
		{
			ra(nil_a);
		}
		i++;
	}
	arg_3(nil_a);
	bottom_order(nil_a, nil_b);
	while (nil_a->next->rank != 1)
		pa(nil_a, nil_b);
	return (0);
}

int	arg_3_to_6(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	if (argc == 4)
		arg_3(nil_a);
	else if (argc == 5)
		arg_4(nil_a, nil_b);
	else if (argc == 6)
		arg_5(nil_a, nil_b);
	else if (argc == 7)
		arg_6(nil_a, nil_b);
	return (0);
}

int	operation_stack(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p_a;
	t_bi_list	*p_b;

	p_a = nil_a;
	p_b = nil_a;
	if (argc <= 7)
	{
		if (argc == 2)
			return (0);
		else if (argc == 3){
			if (nil_a->next->value > nil_a->prev->value)
				sa(nil_a);
		}
		else if (argc >= 4 && argc <= 7)
			arg_3_to_6(argc, nil_a, nil_b);
	}
	else
		Qsort(nil_a, nil_b);
	return (0);
}
