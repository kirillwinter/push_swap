/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdm_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:11:32 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 19:52:31 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->la)
		return ;
	push = stack->a[stack->la - 1];
	i = stack->la - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = push;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *stack, int print)
{
	int	push;
	int	i;

	if (!stack->lb)
		return ;
	push = stack->b[stack->lb - 1];
	i = stack->lb - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = push;
	if (print == 1)
		write(1, "rra\n", 4);
}


void	ps_rrr(t_stack *stack, int print)
{
	ps_rra(stack, 0);
	ps_rrb(stack, 0);
	if (print == 1)
		write(1, "rrr\n", 4);

}
