/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:04:00 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:36 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_stack *stack, int print)
{
	int	tmp[9999];
	int	push;
	int i;

	i = -1;
	if (!stack->lb)
		return ;
	push = stack->b[0];
	while (++i < stack->la)
		tmp[i] = stack->a[i];
	i = -1;
	stack->a[0] = push;
	while (++i < stack->la)
		stack->a[i + 1] = tmp[i];
	stack->la++;
	i = -1;
	while (++i < stack->lb)
		stack->b[i] = stack->b[i + 1];
	stack->lb--;
	if (print == 1)
		write(1, "pa\n", 3);
}

void	ps_pb(t_stack *stack, int print)
{
	int	tmp[9999];
	int	push;
	int i;

	i = -1;
	if (!stack->la)
		return ;
	push = stack->a[0];
	while (++i < stack->lb)
		tmp[i] = stack->b[i];
	i = -1;
	stack->b[0] = push;
	while (++i < stack->lb)
		stack->b[i + 1] = tmp[i];
	stack->lb++;
	i = -1;
	while (++i < stack->la)
		stack->a[i] = stack->a[i + 1];
	stack->la--;
	if (print == 1)
		write(1, "pb\n", 3);
}
