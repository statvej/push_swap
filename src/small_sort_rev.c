/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:04:54 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 14:57:05 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_sort_two(t_stack **b)
{
	if ((*b)->val < (*b)->next->val)
		sb(b);
}

void	rev_sort_three(t_stack **b)
{
	t_stack	*stack_mid;
	int		bottom;
	int		top;
	int		mid;

	stack_mid = (*b)->next;
	top = (*b)->val;
	mid = stack_mid->val;
	bottom = stack_mid->next->val;
	if (top < mid && bottom < top)
		sb(b);
	else if (top < mid && mid < bottom)
	{
		sb(b);
		rrb(b);
	}
	else if (bottom < mid && top < bottom)
		rb(b);
	else if (mid < bottom && bottom < top)
	{
		sb(b);
		rb(b);
	}
	else if (mid < top && top < bottom)
		rrb(b);
}
