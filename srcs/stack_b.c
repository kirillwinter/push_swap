/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:46 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/14 21:16:56 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_last_3_in_b(t_stack *stack, int *count_block, int *n_block)
{
	if (count_block[(*n_block)] == 1)
	{
		ps_pa(stack, 1);
	}
	else if (count_block[(*n_block)] == 2)
	{
		ps_pa(stack, 1);
		ps_pa(stack, 1);
	}
	else if (count_block[(*n_block)] == 3)
	{
		ps_pa(stack, 1);
		ps_pa(stack, 1);
		ps_pa(stack, 1);
	}
	count_block[(*n_block)] = 0;
}

static int	check_move_val_b(int *arr, int len, int mid)
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

static void	rottate_in_block_b(t_stack *stack, int n_block, int *count_r)
{
	if (n_block != 0)
	{
		while ((*count_r))
		{
			ps_rrb(stack, 1);
			(*count_r)--;
		}
	}
}

static void	move_b(t_stack *stack, int *count_block, int *n_block, int *count_r)
{
	int mid;
	int	pos;

	mid = find_median(stack->b, count_block[(*n_block)]);
	pos = check_move_val_b(stack->b, count_block[(*n_block)] - 1, mid) + 1;
	while (pos)
	{
		if (stack->b[0] > mid)
		{
			ps_pa(stack, 1);
			count_block[(*n_block)]--;
		}
		else
		{
			ps_rb(stack, 1);
			(*count_r)++;
		}
		pos--;
	}
}

void		sort_b(t_stack *stack, int *count_block, int *n_block)
{
	int	count_r;

	count_r = 0;
	if (count_block[(*n_block)] <= 3)
		check_last_3_in_b(stack, count_block, n_block);
	else
	{
		move_b(stack, count_block, n_block, &count_r);
		rottate_in_block_b(stack, (*n_block), &count_r);
	}
}
