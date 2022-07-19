/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:56:02 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 18:43:43 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

//in the returned array first element is the size of it
int	*stack_to_arr(t_stack *stack)
{
	int		stack_size;
	int		*ret;
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	stack_size = get_stack_size(stack);
	ret = (int *)malloc(sizeof(int) * (stack_size + 1));
	i = 1;
	tmp = stack;
	ret[0] = stack_size;
	while (tmp != NULL)
	{
		ret[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

int	get_stack_mid_val(t_stack *stack)
{
	int	ret;
	int	*arr;
	int	arr_size;

	arr = stack_to_arr(stack);
	arr_size = arr[0];
	ft_bubble_sort(&arr[1], arr[0]);
	ret = arr[arr_size / 2 + 1];
	free(arr);
	return (ret);
}

int	get_stack_val_index(t_stack *stack, int val)
{
	int		ind;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	ind = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			break ;
		tmp = tmp->next;
		ind++;
	}
	return (ind);
}
