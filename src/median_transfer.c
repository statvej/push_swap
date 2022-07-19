/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_transfer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:12:08 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 14:30:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	transfer_below_median(t_stack **a, t_stack **b, int median)
{
	int	stack_size;
	int	i;

	stack_size = get_stack_size(*a);
	i = 1;
	while (i <= stack_size)
	{
		if ((*a)->val < median)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
