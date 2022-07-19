/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:08:24 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 15:30:16 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*prev;

	if (!stack)
		return ;
	if (!(*stack)->next)
		return ;
	iter = *stack;
	while (iter->next != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	prev->next = NULL;
	iter->next = *stack;
	*stack = iter;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

void	silent_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
