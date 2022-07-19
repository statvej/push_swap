/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:42:35 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 18:49:00 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_next;

	if (!stack)
		return ;
	temp = *stack;
	while (temp)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	*stack = NULL;
}
