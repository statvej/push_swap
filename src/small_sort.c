/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:38 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 15:08:41 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	sort_three(t_stack **a)
{
	t_stack	*stack_mid;
	int		bottom;
	int		top;
	int		mid;

	stack_mid = (*a)->next;
	top = (*a)->val;
	mid = stack_mid->val;
	bottom = stack_mid->next->val;
	if (top > mid && bottom > top)
		sa(a);
	else if (top > mid && mid > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (bottom > mid && top > bottom)
		ra(a);
	else if (mid > bottom && bottom > top)
	{
		sa(a);
		ra(a);
	}
	else if (mid > top && top > bottom)
		rra(a);
}

void	sort_four_to_six(t_stack **a, t_stack **b)
{
	int	median;
	int	size_a;
	int	size_b;
	int	return_count;

	return_count = 0;
	median = get_stack_mid_val(*a);
	transfer_below_median(a, b, median);
	size_a = get_stack_size(*a);
	size_b = get_stack_size(*b);
	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	if (size_b == 2)
		rev_sort_two(b);
	else if (size_b == 3)
		rev_sort_three(b);
	while (return_count < size_b)
	{
		pa(a, b);
		return_count++;
	}
}

void	small_sort(t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
		sort_two(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac >= 5 && ac <= 7)
		sort_four_to_six(a, b);
}
