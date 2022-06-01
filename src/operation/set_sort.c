/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:26:54 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/03 22:27:47 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	set_sorted_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	while (nil_a->next->rank == nil_a->sorted_rank + 1)
	{
		sort_set_operation(nil_a);
		p = nil_a->next;
	}
	if (is_sorted(nil_a))
	{
		ft_sortdone();
	}
	return (0);
}

void	sort_set_operation(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->next;
	p->sorted = 2;
	nil_a->sorted_rank = p->rank;
	nil_a->awant = p->rank + 1;
	ra(nil_a);
	return ;
}
