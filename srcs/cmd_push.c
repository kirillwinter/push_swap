/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:04:00 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/14 16:21:53 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->lb)
		return ;
	push = stack->b[0];
	i = stack->la;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = push;
	stack->la++;
	i = 0;
	while (i < stack->lb - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->lb--;
	if (print == 1)
		write(1, "pa\n", 3);
}

void	ps_pb(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->la)
		return ;
	push = stack->a[0];
	i = stack->lb;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = push;
	stack->lb++;
	i = 0;
	while (i < stack->la - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->la--;
	if (print == 1)
		write(1, "pb\n", 3);
}
