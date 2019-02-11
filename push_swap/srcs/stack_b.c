/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:46 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 15:18:30 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_last_3_in_block_b(t_stack *stack, int *count_block, int *n_block)
{
	if (count_block[(*n_block)] == 1)
	{
		ps_pa(stack);
		(*n_block)--;
	}
	else if(count_block[(*n_block)] == 2)
	{
		ps_pa(stack);
		ps_pa(stack);
		if (stack->a[0] > stack->a[1])
			ps_sa(stack);
		(*n_block)--;
	}
	else if (count_block[(*n_block)] == 3)
	{
		ps_pa(stack);
		ps_pa(stack);
		ps_pa(stack);
		sort_top_three_a(stack);
		(*n_block)--;
	}
}

void	sort_in_stack_b(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;

	mid = find_median(stack->b, count_block[(*n_block)]);
	ft_printf("mid = %d\n", mid);
	ft_printf("кол-во элементов в блоке = %d\n", count_block[(*n_block)]);
	ft_printf("номер блока = %d\n", (*n_block));
	count_r = 0;
	while (count_block[(*n_block)] - count_r > 0)
	{
		print_stack(stack);
		if (count_block[(*n_block)] - count_r == 1 && stack->b[0] <= mid)
			break ;
		if (stack->b[0] > mid)
		{
			ps_pa(stack);
			count_block[(*n_block)]--;
		}
		else
		{
			ps_rb(stack);
			count_r++;
		}
		print_stack(stack);
	}
}