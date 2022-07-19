/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:30:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 13:09:19 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_op_sub(t_transf_price *tps, t_stack **a, t_stack **b)
{
	if (tps->move_count[0] > 0)
	{
		ra(a);
		tps->move_count[0] -= 1;
	}
	if (tps->move_count[0] < 0)
	{
		rra(a);
		tps->move_count[0] += 1;
	}
	if (tps->move_count[1] > 0)
	{
		rb(b);
		tps->move_count[1] -= 1;
	}
	if (tps->move_count[1] < 0)
	{
		rrb(b);
		tps->move_count[1] += 1;
	}
}

void	exec_op_move(t_transf_price tps, t_stack **a, t_stack **b)
{
	while (tps.move_count[0] != 0 || tps.move_count[1] != 0)
	{
		if (tps.move_count[0] > 0 && tps.move_count[1] > 0)
		{
			rr(a, b);
			tps.move_count[0] -= 1;
			tps.move_count[1] -= 1;
		}
		else if (tps.move_count[0] < 0 && tps.move_count[1] < 0)
		{
			rrr(a, b);
			tps.move_count[0] += 1;
			tps.move_count[1] += 1;
		}
		else
			exec_op_sub(&tps, a, b);
	}
	pa(a, b);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int				tp_size;
	int				tp_index;
	int				size_a;
	t_transf_price	*tp;

	if (check_is_sorted(*a))
		return ;
	move_lis_to_b(a, b);
	while (*b)
	{
		tp = get_transf_price(*a, *b, &tp_size);
		tp_index = pick_best_move_index(tp, tp_size);
		exec_op_move(tp[tp_index], a, b);
		free(tp);
	}
	size_a = get_stack_size(*a);
	if (get_stack_val_index(*a, get_stack_max_elem(*a)) <= size_a / 2)
		while (get_stack_val_index(*a, get_stack_max_elem(*a)) != size_a - 1)
			ra(a);
	else
		while (get_stack_val_index(*a, get_stack_max_elem(*a)) != size_a - 1)
			rra(a);
}
