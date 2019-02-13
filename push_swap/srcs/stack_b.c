/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:46 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 13:50:23 by wballaba         ###   ########.fr       */
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
	count_block[(*n_block)] = 0;
}

int		check_move_val_b(int *arr, int len, int mid)
{
	int	pos;

	pos = len;
	while (len >= 0)
	{
		if (arr[len] > mid)
			return (len);
		len--;
	}
	return (len);
}

void	sort_in_stack_b(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;
	int	pos;

	count_r = 0;
	if (count_block[(*n_block)] <= 3)
		check_last_3_in_block_b(stack, count_block, n_block);
	else
	{
		mid = find_median(stack->b, count_block[(*n_block)]);
		pos = check_move_val_b(stack->b, count_block[(*n_block)] -1, mid) + 1;
		while (pos)
		{
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
			pos--;
			print_stack(stack, count_block, n_block);
		}
		if ((*n_block) != 0)
		{
			while (count_r)
			{
				ps_rrb(stack);
				count_r--;
			}
		}
		print_stack(stack, count_block, n_block);
	}
}