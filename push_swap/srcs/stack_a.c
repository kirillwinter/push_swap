/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 15:18:31 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_last_three_a(t_stack *stack)
{
	int	max;
	int i;

	i = 0;
	max = stack->a[i];
	while(i < 3)
	{
		if (max < stack->a[i])
			max = stack->a[i];
		i++;
	}
	i = 0;
	while (max != stack->a[i])
		i++;
	if (i == 0)
		ps_ra(stack);
	else if (i == 1)
		ps_rra(stack);
	if (stack->a[0] > stack->a[1])
		ps_sa(stack);
}

void	sort_top_three_a(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
		return ;
	else if (stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
	{
		ps_ra(stack);
		ps_sa(stack);
		ps_rra(stack);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		ps_sa(stack);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
	{
		ps_ra(stack);
		ps_sa(stack);
		ps_rra(stack);
		ps_sa(stack);
	}
	else if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
	{
		ps_sa(stack);
		ps_ra(stack);
		ps_sa(stack);
		ps_rra(stack);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ps_ra(stack);
		ps_sa(stack);
		ps_rra(stack);
		ps_sa(stack);
		ps_ra(stack);
		ps_sa(stack);
		ps_rra(stack);
	}
}

void	sort_in_stack_a(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;

	mid = find_median(stack->a, stack->la);
	(*n_block)++;
	count_r = 0;
	ft_printf("mid = %d\n", mid);
	while (stack->la - count_r > 0)
	{
		if (stack->a[0] < mid)
		{
			ps_pb(stack);
			count_block[(*n_block)]++;
		}
		else
		{
			ps_ra(stack);
			count_r++;
		}
		print_stack(stack);
	}
	ft_printf("кол-во элементов в блоке = %d\n", count_block[(*n_block)]);
	ft_printf("номер блока = %d\n", n_block);
	print_stack(stack);
}

