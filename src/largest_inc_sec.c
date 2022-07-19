/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_inc_sec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:58:52 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 18:17:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

int	*lis_sub(int size, int lis_length, int *arr, int *index)
{
	int	i;
	int	tmp;
	int	*answer;

	answer = (int *)malloc((lis_length + 2) * sizeof(int));
	i = size - 1;
	tmp = lis_length;
	while (i >= 0)
	{
		if (index[i] == tmp)
			answer[tmp--] = arr[i];
		i--;
	}
	return (answer);
}

int	*get_lis(int *arr, int size, int *lis_size, int i)
{
	int	tmp;
	int	lis_length;
	int	*answer;
	int	*lis;
	int	*index;

	lis_length = -1;
	lis = (int *)malloc(sizeof(int) * size);
	index = (int *)malloc(sizeof(int) * size);
	lis[0] = arr[0];
	i = 1;
	while (i < size)
		lis[i++] = INT_MAX;
	i = 1;
	while (i < size)
	{
		index[i] = search_replace(lis, 0, i, arr[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	answer = lis_sub(size, lis_length, arr, index);
	*lis_size = lis_length + 1;
	multi_free(2, lis, index);
	return (answer);
}

int	int_in_arr(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	move_lis_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*lis;
	int		lis_size;
	int		i;
	int		*arr;

	tmp = copy_stack(*a);
	put_min_elem_on_top(&tmp, STACK_UNDEF);
	arr = stack_to_arr(tmp);
	lis = get_lis(&arr[1], arr[0], &lis_size, 0);
	arr[0] = get_stack_size(*a);
	i = 1;
	while (i <= arr[0])
	{
		if (int_in_arr((*a)->val, lis, lis_size))
			ra(a);
		else
			pb(a, b);
		i++;
	}
	free_stack(&tmp);
	multi_free(2, arr, lis);
}
