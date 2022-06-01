/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:30 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/04 02:30:50 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	sort_3_a_first(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->next;
	if (p->next->rank < p->next->next->rank)
		return (0);//123
	else if (p->rank < p->next->next->rank)
	{//132
		sa(nil_a);
		ra(nil_a);
	}
	else if (p->rank > p->next->next->rank)
		rra(nil_a);//231
	return (1);
}

int	sort_3_a_second(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->next;
	if (p->rank < p->next->next->rank)
		sa(nil_a);//213
	else if (p->rank > p->next->next->rank
		&& p->next->rank < p->next->next->rank)
	{
		ra(nil_a);//312
		return (0);
	}
	else if (p->rank > p->next->next->rank)
	{//321
		sa(nil_a);
		rra(nil_a);
	}
	return (0);
}

int	arg_3(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (p->rank < p->next->rank)
	{
		if (sort_3_a_first(nil))
			return (1);
	}
	else
	{
		if (sort_3_a_second(nil))
			return (1);
	}
	return (0);
}

 