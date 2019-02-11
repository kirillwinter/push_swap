/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 14:41:34 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_median(int *arr, int len)
{
	int	tmp[len];
	int	i;

	i = -1;
	while (++i < len)
		tmp[i] = arr[i];
	i = 0;
	while (i < len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (tmp[len / 2]);

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

void	sort_last_three(t_stack *stack)
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

int		push_swap(t_stack *stack)
{
	int mid;
	int	count_r;
	int	count_block[] = {0, 0, 0, 0, 0, 0};
	int	n_block;

	n_block = -1;
	print_stack(stack);
	while(stack->la > 3)
	{
		sort_in_stack_a(stack, count_block, &n_block);
	}
	if (stack->la == 3)
		sort_last_three(stack);
	else if(stack->la == 2 && stack->a[0] > stack->a[1])
		ps_sa(stack);
	
	while (n_block >= 0)
	{
		if (count_block[n_block] <= 3)
			check_last_3_in_block_b(stack, count_block, &n_block);
		else 
		{
			mid = find_median(stack->b, count_block[n_block]);
			ft_printf("mid = %d\n", mid);
			ft_printf("кол-во элементов в блоке = %d\n", count_block[n_block]);
			ft_printf("номер блока = %d\n", n_block);
			count_r = 0;
			while (count_block[n_block] - count_r > 0)
			{
				print_stack(stack);
				if (count_block[n_block] - count_r == 1 && stack->b[0] <= mid)
					break ;
				if (stack->b[0] > mid)
				{
					ps_pa(stack);
					count_block[n_block]--;
				}
				else
				{
					ps_rb(stack);
					count_r++;
				}
				print_stack(stack);
			}

			if (count_r && n_block != 0)
			{
				while (count_r)
				{
					ps_rrb(stack);
					count_r--;
					print_stack(stack);
				}
			}
			ft_printf("count_block[n_block] = %d\n", count_block[n_block]);
			if (count_block[n_block] == 0)
				n_block--;
		}
	}
	ft_printf("n_block = %d\n", n_block);
	print_stack(stack);
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		valid;

	g_count = 0;
	i = -1;
	valid = 1;
	stack = create_new_stack(argc - 1);
	while (++i < argc - 1)
	{
		stack->a[i] = ps_atoi(argv[i + 1], stack, &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (0);
	}
	if (!push_swap(stack))
		return (0);
	check_vals(stack, i);
	del_stack(stack);
	return (1);
}
