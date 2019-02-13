/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:11:38 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 19:44:40 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->la)
		return ;
	i = 0;
	push = stack->a[0];
	while (i < stack->la - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = push;
	if (print == 1)
		write(1, "ra\n", 3);
}


void	ps_rb(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->lb)
		return ;
	i = 0;
	push = stack->b[0];
	while (i < stack->lb - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = push;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	ps_rr(t_stack *stack, int print)
{
	ps_ra(stack, 0);
	ps_ra(stack, 0);
	if (print == 1)
		write(1, "rr\n", 3);
}
