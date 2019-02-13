/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 14:20:10 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_last_3_in_block_a(t_stack *stack, int *sorted, int unsorted)
{
	if (unsorted == 1)
		(*sorted)++;
	else if (unsorted == 2)
	{
		if (stack->a[0] > stack->a[1])
			ps_sa(stack);
		(*sorted) += 2;
	}
	else if (unsorted == 3)
	{
		sort_top_three_a(stack);
		(*sorted) += 3;
	}
}

int		check_move_val_a(int *arr, int len, int mid)
{
	int	pos;

	pos = len;
	while (len >= 0)
	{
		if (arr[len] < mid)
			return (len);
		len--;
	}
	return (len);
}

void	sort_in_stack_a(t_stack *stack, int *count_block, int *n_block, int *sorted)
{
	int mid;
	int	count_r;
	int	unsorted;
	int	pos;

	unsorted = stack->la - (*sorted);
	if (unsorted <= 3)
		check_last_3_in_block_a(stack, sorted, unsorted);
	else
	{
		mid = find_median(stack->a, count_block[(*n_block)]);
		unsorted = stack->la - (*sorted);
		(*n_block)++;
		count_r = 0;
		pos = check_move_val_a(stack->a, unsorted, mid) + 1;
		// while(unsorted - count_r > 0)
		while(pos)
		{
			if (stack->a[0] < mid)
			{
				ps_pb(stack);
				count_block[(*n_block)]++;
				print_stack(stack, count_block, n_block);
			}
			else
			{
				ps_ra(stack);
				count_r++;
				print_stack(stack, count_block, n_block);
			}
			pos--;
		}
		print_stack(stack, count_block, n_block);
		while (count_r)
		{
			ps_rra(stack);
			count_r--;
		}
		print_stack(stack, count_block, n_block);
		sort_in_stack_a(stack, count_block, n_block, sorted);
	}
}
