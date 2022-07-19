/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_detec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:57:47 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 19:15:43 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_dup_sub(t_stack *stack, int val)
{
	t_stack		*tmp;
	int			dup_count;

	tmp = stack;
	dup_count = 0;
	while (tmp != NULL)
	{
		if (val == tmp->val)
			dup_count++;
		if (dup_count == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_dup_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (check_dup_sub(stack, tmp->val))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_is_int(int ac, char **av)
{
	int	i;
	int	j;
	int	min_toler;

	i = 1;
	while (i < ac)
	{
		j = 0;
		min_toler = 0;
		while (av[i][j])
		{	
			if (j != 0 && av[i][j] == '-')
				return (0);
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != ' ')
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->val > tmp->next->val)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	sub_error(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
