/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:12:05 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 14:46:09 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		ft_printf("Stack is empty\n");
	tmp = stack;
	ft_printf("_\n");
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("_\n\n");
}

// void	print_arr(int *arr, int size)
// {
// 	int i;
// 	for (i = 0; i < size; i++)
// 		ft_printf("%d ", arr[i]);
// 	ft_printf("\n");
// }

// void print_t_transf(t_transf_price * tp, int tp_size){
// 	int i = 0;
// 	while (i < tp_size)
// 	{
// 		ft_printf("Complexity is [%d, %d], and value is %d\n",
// 			tp[i].move_count[0], tp[i].move_count[1], tp[i].val);
// 		i++;
// 	}
// }
