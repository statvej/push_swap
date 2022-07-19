/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:52:58 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 15:31:38 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (!stack)
		return ;
	if (!(*stack)->next)
		return ;
	tmp = *stack;
	iter = *stack;
	*stack = tmp->next;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	silent_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
