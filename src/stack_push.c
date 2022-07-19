/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:05:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 15:23:58 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	*b = temp_b->next;
	*a = temp_b;
	temp_b->next = temp_a;
	ft_printf("pa\n");
}

void	silent_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	*b = temp_b->next;
	*a = temp_b;
	temp_b->next = temp_a;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a->next;
	*b = temp_a;
	temp_a->next = temp_b;
	ft_printf("pb\n");
}

void	silent_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a->next;
	*b = temp_a;
	temp_a->next = temp_b;
}
