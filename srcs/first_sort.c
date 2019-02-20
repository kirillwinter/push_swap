/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:46:58 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 15:36:41 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_three_a2(t_stack *stack)
{
	if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
	{
		ps_sa(stack, 1);
		ps_ra(stack, 1);
		ps_sa(stack, 1);
		ps_rra(stack, 1);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ps_ra(stack, 1);
		ps_sa(stack, 1);
		ps_rra(stack, 1);
		ps_sa(stack, 1);
		ps_ra(stack, 1);
		ps_sa(stack, 1);
		ps_rra(stack, 1);
	}
}

void	sort_top_three_a(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
		return ;
	else if (stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
	{
		ps_ra(stack, 1);
		ps_sa(stack, 1);
		ps_rra(stack, 1);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		ps_sa(stack, 1);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
	{
		ps_ra(stack, 1);
		ps_sa(stack, 1);
		ps_rra(stack, 1);
		ps_sa(stack, 1);
	}
	else
		sort_top_three_a2(stack);
}

void	sort_last_three_a(t_stack *stack)
{
	int	max;
	int i;

	i = 0;
	max = stack->a[i];
	while (i < 3)
	{
		if (max < stack->a[i])
			max = stack->a[i];
		i++;
	}
	i = 0;
	while (max != stack->a[i])
		i++;
	if (i == 0)
		ps_ra(stack, 1);
	else if (i == 1)
		ps_rra(stack, 1);
	if (stack->a[0] > stack->a[1])
		ps_sa(stack, 1);
}

void	first_move_a(t_stack *stack, int *count_block, int *n_block)
{
	int mid;
	int	pos;

	mid = find_median(stack->a, stack->la);
	(*n_block)++;
	pos = check_move_val_a(stack->a, stack->la, mid) + 1;
	while (pos)
	{
		if (stack->a[0] < mid)
		{
			ps_pb(stack, 1);
			count_block[(*n_block)]++;
		}
		else
			ps_ra(stack, 1);
		pos--;
	}
}

void	first_sort(t_stack *stack, int *count_block, int *n_block, int *sorted)
{
	while (stack->la > 3)
	{
		if (check_vals(stack, stack->la, 0))
		{
			(*sorted) = stack->la;
			return ;
		}
		first_move_a(stack, count_block, n_block);
	}
	if (stack->la == 3)
	{
		sort_last_three_a(stack);
		(*sorted) = 3;
	}
	else if (stack->la == 2)
	{
		if (stack->a[0] > stack->a[1])
			ps_sa(stack, 1);
		(*sorted) = 2;
	}
	else if (stack->la == 1)
		(*sorted) = 1;
}
