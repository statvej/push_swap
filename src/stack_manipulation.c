/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:25:48 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 16:10:35 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stack_min_elem(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (tmp->val < min)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

int	get_stack_max_elem(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (tmp->val > min)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

void	put_min_elem_on_top(t_stack **stack, int stack_id)
{
	int	min_elem;
	int	ind;
	int	stack_size;
	int	i;

	min_elem = get_stack_min_elem(*stack);
	ind = get_stack_val_index(*stack, min_elem);
	stack_size = get_stack_size(*stack);
	i = 0;
	if (ind > stack_size / 2)
	{
		while (i < stack_size - ind)
		{
			rev_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < ind)
		{
			rotate(stack);
			i++;
		}
	}
}

t_stack	*copy_stack(t_stack *src)
{
	t_stack	*dst;
	t_stack	*tmp;

	dst = NULL;
	if (!src)
		return (NULL);
	tmp = src;
	while (tmp != NULL)
	{
		add_to_stack(&dst, tmp->val);
		tmp = tmp->next;
	}
	reverse_stack(&dst);
	return (dst);
}
