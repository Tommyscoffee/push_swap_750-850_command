/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:45:24 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/05 20:48:17 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	make_pivot_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	pivot;

	pivot = (((nil_a->stack_size + nil_a->sorted_rank) / 2));
	if ((nil_a->stack_size + nil_a->sorted_rank) % 2)
		pivot++;
	return (pivot);
}

int	make_pivot_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	pivot;

	pivot = (nil_a->awant - 1) + nil_b->size_now / 2;
	if ((nil_b->size_now) % 2)
		pivot++;
	return (pivot);
}
