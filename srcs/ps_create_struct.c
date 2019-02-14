/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:30:06 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/14 20:49:50 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create_new_stack(int len)
{
	t_stack	*stack;
	int		i;

	i = -1;
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	if (!(stack->a = (int *)malloc(sizeof(int) * len)))
		return (0);
	if (!(stack->b = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (++i < len)
		stack->b[i] = 0;
	stack->la = len;
	stack->lb = 0;
	return (stack);
}

int			del_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return (0);
}

int			ps_error(int *valid)
{
	write(2, "Error\n", 6);
	(*valid) = 0;
	return (0);
}
