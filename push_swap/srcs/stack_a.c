/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:47:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 23:08:02 by wballaba         ###   ########.fr       */
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

void	first_sort_in_stack_a(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;

	mid = find_median(stack->a, stack->la);
	(*n_block)++;
	count_r = 0;
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
	}
}

void	sort_in_stack_a(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	count_r;

	if (count_block[(*n_block)] == 1)
		{
			count_block[(*n_block)] =0;
			g_flag = 1;
		}
	else if (count_block[(*n_block)] == 2)
	{
		if (stack->a[0] > stack->a[1])
			ps_sa(stack);
		count_block[(*n_block)] =0;
		g_flag = 1;
	}
	else if (count_block[(*n_block)] == 3)
	{
		sort_top_three_a(stack);
		count_block[(*n_block)] =0;
		g_flag = 1;
	}
	else
	{
		mid = find_median(stack->a, count_block[(*n_block)]);
		count_r = 0;
		count_block[(*n_block + 1)] = 0;
		while(count_block[(*n_block)] - count_r > 0)
		{
			if (stack->a[0] < mid)
			{
				ps_pb(stack);
				count_block[(*n_block)]--;
				count_block[(*n_block + 1)]++;
			}
			else
			{
				ps_ra(stack);
				count_r++;
			}
		}
		print_stack(stack);
		count_block[(*n_block)] = count_r;
		while (count_r)
		{
			ps_rra(stack);
			count_r--;
		}
		print_stack(stack);
		(*n_block)++;
		g_flag = 0;
		// sort(stack, count_block, n_block);
		// sort_in_stack_a(stack, count_block, n_block);
	}
}
