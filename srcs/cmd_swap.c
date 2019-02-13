/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:02:40 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 16:57:12 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_stack *stack, int print)
{
	if (stack->la >= 2)
		ft_swap(&stack->a[0], &stack->a[1]);
	if (print == 1)
		write(1, "sa\n", 3);
}
void	ps_sb(t_stack *stack, int print)
{
	if (stack->lb >= 2)
		ft_swap(&stack->b[0], &stack->b[1]);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ps_ss(t_stack *stack, int print)
{
	if (stack->la >= 2 && stack->lb >= 2)
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_swap(&stack->b[0], &stack->b[1]);
	}
	if (print == 1)
		write(1, "ss\n", 3);
}
