/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:02:40 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/08 14:40:36 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_sa(t_stack *stack)
{
	if (stack->la >= 2)
		ft_swap(&stack->a[0], &stack->a[1]);
}
void	ps_sb(t_stack *stack)
{
	if (stack->lb >= 2)
		ft_swap(&stack->b[0], &stack->b[1]);
}

void	ps_ss(t_stack *stack)
{
	if (stack->la >= 2 && stack->lb >= 2)
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_swap(&stack->b[0], &stack->b[1]);
	}
}

void	ps_pa(t_stack *stack)
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
}

void	ps_pb(t_stack *stack)
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
}
