/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:46 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 22:42:51 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_last_3_in_block_b(t_stack *stack, int *count_block, int *n_block)
{
	if (count_block[(*n_block)] == 1)
	{
		ps_pa(stack);
	}
	else if(count_block[(*n_block)] == 2)
	{
		ps_pa(stack);
		ps_pa(stack);
	}
	else if (count_block[(*n_block)] == 3)
	{
		ps_pa(stack);
		ps_pa(stack);
		ps_pa(stack);
	}
}

void	sort_in_stack_b(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;

	count_r = 0;
	if (count_block[(*n_block)] <= 3)
	{
		check_last_3_in_block_b(stack, count_block, n_block);
		return ;
	}
	else
	{
		mid = find_median(stack->b, count_block[(*n_block)]);
		count_block[(*n_block + 1)] = 0;
		while (count_block[(*n_block)] - count_r > 0)
		{
			// if (count_block[(*n_block)] - count_r == 1 && stack->b[0] <= mid)
			// 	break ;
			if (stack->b[0] > mid)
			{
				ps_pa(stack);
				count_block[(*n_block)]--;
				count_block[(*n_block + 1)]++;
			}
			else
			{
				ps_rb(stack);
				count_r++;
			}
			print_stack(stack);
		}
		if ((*n_block) != 0)
		{
			while (count_r)
			{
				ps_rrb(stack);
				count_r--;
			}
		}
		
		(*n_block)++;
		// sort_in_stack_b(stack, count_block, n_block);
	}
}