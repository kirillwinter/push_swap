/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdm_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:11:32 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 18:17:58 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_stack *stack)
{
	int	tmp[stack->la];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[j] = stack->a[stack->la - 1];
	j++;
	while (j < stack->la)
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

void	ps_rrb(t_stack *stack)
{
	int	tmp[stack->lb];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[j] = stack->b[stack->lb - 1];
	j++;
	while (j < stack->lb)
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

void	ps_rrr(t_stack *stack)
{
	ps_rra(stack);
	ps_rrb(stack);
}
