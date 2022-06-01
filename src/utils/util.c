/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:46:28 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/05 20:52:34 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	is_sorted(t_bi_list *nil_a)
{
	t_bi_list	*p;
	int			i;

	i = 0;
	p = nil_a->next;
	while (p->next != nil_a && nil_a->size_now == nil_a->stack_size)
	{
		if (p->rank > p->next->rank)
			return (0);
		p = p->next;
		i++;
	}
	if (nil_a->size_now != nil_a->stack_size)
		return (0);
	return (1);
}

void	ft_sortdone(void)
{
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, "sort done\n", 10);
	write(STDOUT_FILENO, END, ft_strlen(END));
	write(STDOUT_FILENO, GREEN, ft_strlen(GREEN));
	write(STDOUT_FILENO, "command_num =", 13);
	write(STDOUT_FILENO, ft_itoa(command_num), ft_strlen(ft_itoa(command_num)));
	write(STDOUT_FILENO, END, ft_strlen(END));
	printf("\n");
	exit(1);
	return ;
}
