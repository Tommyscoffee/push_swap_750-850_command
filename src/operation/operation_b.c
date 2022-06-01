/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 02:13:27 by akihito           #+#    #+#             */
/*   Updated: 2022/02/04 02:40:33 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	arg_3_b(t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	if (p->rank > p->next->rank)
	{//1 > 2
		printf("sort_3_first\n");
		if (sort_3_b_first(nil_b))
			return (1);
		return (0);
	}
	else//1 > 2
	{
		if (sort_3_b_second(nil_b))
			return (1);
		return (0);
	}
	return (1);
}

int	sort_3_b_first(t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	if (p->next->rank > p->next->next->rank)
		return (0);
	else if (p->rank < p->next->next->rank)
		rrb(nil_b);
	else if (p->next->rank < p->next->next->rank)
	{
		rb(nil_b);
		sb(nil_b);
		rrb(nil_b);
	}
	return (0);
}

int	sort_3_b_second(t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	if (p->next->rank > p->next->next->rank)
	{//1 > 2 && 2 < 3
		if (p->rank > p->next->next->rank)
			sb(nil_b);
		else if (p->rank < p->next->next->rank)
			rb(nil_b);
		return (0);
	}
	if (p->rank > p->next->next->rank)
		sb(nil_b);
	else if (p->rank < p->next->next->rank)
	{
		sb(nil_b);
		rrb(nil_b);
	}
	return (0);
}

// int	arg_5_b(t_bi_list *nil_a, t_bi_list *nil_b)
// {//yllow3を参照　rank1,2をpbする。し終わったらスタックAをソート
// 	t_bi_list	*p;
// 	int			i;

// 	i = 0;
// 	p = nil_b->next;
// 	printf("stack_size = %d\n", nil_b->size_now);
// 	while (i < nil_b->size_now)
// 	{
// 		printf("stack_size = %d\n", nil_b->size_now);
// 		if (p->rank == 1 || p->rank == 2)
// 		{
// 			pb(nil_a, nil_b);
// 		}
// 		else
// 		{
// 			ra(nil_a);
// 		}
// 		p = nil_a->next;
// 		i++;
// 		// print_stacks(nil_a, nil_b);
// 	}
// 	arg_3(nil_a);
// 	arg_2(nil_b);
// 	print_stacks(nil_a, nil_b);
// 	pa(nil_a, nil_b);
// 	pa(nil_a, nil_b);
// 	return (0);
// }
