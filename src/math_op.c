/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:58:45 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 16:06:58 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (a * (-1));
}
