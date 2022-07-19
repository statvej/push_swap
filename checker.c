/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:25:43 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/18 18:40:22 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	if_statements(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		silent_pa(a, b);
	else if (!ft_strcmp(cmd, "pb\n"))
		silent_pb(a, b);
	else if (!ft_strcmp(cmd, "sa\n"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		silent_ss(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		silent_rr(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		rev_rotate(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rev_rotate(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		silent_rrr(a, b);
	else
		return (0);
	return (1);
}

// int	if_statements_with_output(t_stack **a, t_stack **b, char *cmd)
// {
// 	if (!ft_strcmp(cmd, "pa\n"))
// 		pa(a, b);
// 	else if (!ft_strcmp(cmd, "pb\n"))
// 		pb(a, b);
// 	else if (!ft_strcmp(cmd, "sa\n"))
// 		sa(a);
// 	else if (!ft_strcmp(cmd, "sb\n"))
// 		sb(b);
// 	else if (!ft_strcmp(cmd, "ss\n"))
// 		ss(a, b);
// 	else if (!ft_strcmp(cmd, "ra\n"))
// 		ra(a);
// 	else if (!ft_strcmp(cmd, "rb\n"))
// 		rb(b);
// 	else if (!ft_strcmp(cmd, "rr\n"))
// 		rr(a, b);
// 	else if (!ft_strcmp(cmd, "rra\n"))
// 		rra(a);
// 	else if (!ft_strcmp(cmd, "rrb\n"))
// 		rrb(b);
// 	else if (!ft_strcmp(cmd, "rrr\n"))
// 		rrr(a, b);
// 	else
// 		return (0);
// 	return (1);
// }
		// if (!if_statements_with_output(&a, &b, cmd))
		// {
		// 	free_stack(&b);
		// 	sub_error(&a);
		// }

void	display_result(t_stack *a, t_stack *b)
{
	if (check_is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

// void	check_for_errno_msg(void)
// {
// 	char	*cmd;

// 	cmd = ft_calloc(sizeof(char), 8);
// 	read(STDERR_FILENO, cmd, 8);
// 	if (!ft_strcmp(cmd, "Error\n"))
// 	{
// 		free(cmd);
// 		exit(0);
// 	}
// 	free(cmd);
// }

int	main(int ac, char **av)
{
	t_stack	*b;
	t_stack	*a;
	char	*cmd;

	if (ac < 2)
		return (0);
	b = NULL;
	a = init_stack_a(ac, av);
	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		if (!if_statements(&a, &b, cmd))
		{
			free_stack(&b);
			sub_error(&a);
		}
		free(cmd);
	}
	display_result(a, b);
	free_stack(&b);
	free_stack(&a);
}
