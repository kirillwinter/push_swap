/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:11:38 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 19:16:14 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_stack *stack)
{
	int	tmp[stack->la];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[stack->la - 1] = stack->a[i];
	i++;
	while (i < stack->la)
	{
		tmp[j] = stack->a[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->la)
	{
		stack->a[i] = tmp[i];
		i++;
	}
}

void	ps_rb(t_stack *stack)
{
	int	tmp[stack->lb];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[stack->lb - 1] = stack->b[i];
	i++;
	while (i < stack->lb)
	{
		tmp[j] = stack->b[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->lb)
	{
		stack->b[i] = tmp[i];
		i++;
	}
}

void	ps_rr(t_stack *stack)
{
	ps_ra(stack);
	ps_ra(stack);
}
