/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_transfer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:07:03 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 16:07:15 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_closest_move(int i, int size)
{
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

//add comparing between prev and current to determine needed position
//(also add special cases for min  and max) 
int	get_position_in_a(int val, t_stack *a)
{
	int		i;
	t_stack	*temp;
	t_stack	*prev;
	int		size_a;
	int		stack_min;

	i = get_stack_max_elem(a);
	temp = a->next;
	prev = a;
	size_a = get_stack_size(a);
	stack_min = get_stack_min_elem(a);
	if (val > i)
		return (get_closest_move(get_stack_val_index(a, i), size_a) + 1);
	if (val < stack_min)
		return (get_closest_move(get_stack_val_index(a, stack_min), size_a));
	i = 1;
	while (temp)
	{
		if (temp->val > val && prev->val < val)
			return (get_closest_move(i, size_a));
		prev = temp;
		temp = temp->next;
		i++;
	}
	return (get_closest_move(i, size_a));
}

//could be optimised by trying to differ + and - values
t_transf_price	*get_transf_price(t_stack *a, t_stack *b, int *tp_size)
{
	int				b_size;
	t_transf_price	*ret;
	int				i;
	t_stack			*temp;

	b_size = get_stack_size(b);
	i = 0;
	temp = b;
	ret = (t_transf_price *)malloc(sizeof(t_transf_price) * b_size);
	while (temp)
	{
		ret[i].val = temp->val;
		ret[i].move_count[0] = get_position_in_a(temp->val, a);
		if (i <= b_size / 2)
			ret[i].move_count[1] = i;
		else
			ret[i].move_count[1] = i - b_size;
		temp = temp->next;
		i++;
	}
	*tp_size = b_size;
	return (ret);
}

int	pick_best_move_index(t_transf_price *tp, int tp_size)
{
	int	i;
	int	best_index;
	int	moves_best;
	int	cm;

	i = 0;
	best_index = -1;
	moves_best = INT_MAX;
	cm = 0;
	while (i < tp_size)
	{
		if (tp[i].move_count[0] * tp[i].move_count[1] > 0)
		{
			cm = max(abs(tp[i].move_count[0]), abs(tp[i].move_count[1]));
		}
		else
			cm = abs(tp[i].move_count[0]) + abs(tp[i].move_count[1]);
		if (cm < moves_best)
		{
			best_index = i;
			moves_best = cm;
		}
		i++;
	}
	return (best_index);
}
