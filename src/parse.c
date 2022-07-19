/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:07:29 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 19:19:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atolongi(const char *str)
{
	long	convert;
	int		sign;
	int		i;

	convert = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = (convert * 10) + (str[i] - '0');
		i++;
	}
	return (convert * sign);
}

static void	sub_error_silent(t_stack **a)
{
	free_stack(a);
	exit(0);
}

void	bracket_parse(t_stack **a, char *ar)
{
	char	**av;
	int		i;
	int		num;

	av = ft_split(ar, ' ');
	i = 0;
	while (av[i])
	{
		num = ft_atolongi(av[i]);
		if (num > 2147483647 || num < -2147483648)
			sub_error(a);
		add_to_stack(a, (int)num);
		i++;
	}
	reverse_stack(a);
	free_double_ptr((void **)av, i);
}

void	normal_parse(t_stack **a, char **av, int ac)
{
	int		i;
	long	num;

	i = ac - 1;
	while (i >= 1)
	{
		num = ft_atolongi(av[i]);
		if (num > 2147483647 || num < -2147483648)
			sub_error(a);
		add_to_stack(a, (int)num);
		i--;
	}
}

//returns pointer to top element of stack A
t_stack	*init_stack_a(int ac, char **av)
{
	long int	num;
	t_stack		*a;

	if (!(check_is_int(ac, av)) || ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	a = NULL;
	if (ac == 2)
		bracket_parse(&a, av[1]);
	else
		normal_parse(&a, av, ac);
	if (check_dup_stack(a))
		sub_error(&a);
	if (check_is_sorted(a))
		sub_error_silent(&a);
	return (a);
}
