/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:04:03 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 16:10:52 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*stack_new(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, int val)
{
	t_stack	*new;

	new = stack_new(val);
	new->next = *stack;
	*stack = new;
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = *stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
}

// t_stack	*init_empty_stack(void)
// {
// 	t_stack	*ret;
// 	ret = (t_stack *)malloc(sizeof(t_stack));
// 	ret->next = NULL;
// }