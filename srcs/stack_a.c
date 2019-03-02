/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 15:37:06 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_last_3_in_block_a(t_stack *stack, int *sorted, int unsorted)
{
	if (unsorted == 1)
		(*sorted)++;
	else if (unsorted == 2)
	{
		if (stack->a[0] > stack->a[1])
			ps_sa(stack, 1);
		(*sorted) += 2;
	}
	else if (unsorted == 3)
	{
		sort_top_three_a(stack);
		(*sorted) += 3;
	}
}

int			check_move_val_a(int *arr, int len, int mid)
{
	len--;
	while (len >= 0)
	{
		if (arr[len] < mid)
			return (len);
		len--;
	}
	return (len);
}

static int	move_a(t_stack *stack, int *count_block, int *n_block, int unsorted)
{
	int mid;
	int	pos;
	int count_r;

	count_r = 0;
	mid = find_median(stack->a, count_block[(*n_block)]);
	(*n_block)++;
	pos = check_move_val_a(stack->a, unsorted, mid) + 1;
	while (pos)
	{
		if (stack->a[0] < mid)
		{
			ps_pb(stack, 1);
			count_block[(*n_block)]++;
		}
		else
		{
			ps_ra(stack, 1);
			count_r++;
		}
		pos--;
	}
	return (count_r);
}

void		sort_a(t_stack *stack, int *count_block, int *n_block, int *sorted)
{
	int	count_r;
	int	unsorted;

	unsorted = stack->la - (*sorted);
	if (check_vals(stack, unsorted, 0))
	{
		(*sorted) += unsorted;
		return ;
	}
	if (unsorted <= 3)
		check_last_3_in_block_a(stack, sorted, unsorted);
	else
	{
		count_r = move_a(stack, count_block, n_block, unsorted);
		while (count_r)
		{
			ps_rra(stack, 1);
			count_r--;
		}
		sort_a(stack, count_block, n_block, sorted);
	}
}
