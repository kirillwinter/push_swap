/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/08 23:19:38 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	find_max_a(t_stack *stack)
// {
// 	int	max;
// 	int i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	max = stack->a[i];
// 	while(i < stack->la)
// 	{
// 		if (max < stack->a[i])
// 			max = stack->a[i];
// 		i++;
// 	}
// 	i = 0;
// 	ft_printf("max = %d\n", max);
// 	while (stack->a[0] != max) //кидаем в б все значения кроме мах
// 	{
// 		ps_pb(stack);
// 		i++;
// 	}
// 	ps_ra(stack); // кидаем вниз а мах
// 	while (max != stack->a[0])
// 	{
// 		ps_pb(stack);
// 		i++;
// 	}
	
	
// }

void	sort_kirilla_krasavchika(int *tmp, int len)
{
	int i;

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
}

int		find_median(int *arr, int len)
{
	int	tmp[len];
	int	i;

	i = 0;
	while (i < len)
	{
		tmp[i] = arr[i];
		i++;
	}
	i = 0;
	sort_kirilla_krasavchika(tmp, len);
	return (tmp[len / 2]);

}

int		sort_last_three(t_stack *stack)
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
	return (0);
}
// ./push_swap 12 64 87 68 868 565 998 2345325 56757 9 2 5 8 4 83
int		push_swap(t_stack *stack)
{
	int mid;
	int	count_r;
	int	count_block[9999];
	int	n_block;

	mid = find_median(stack->a, stack->la);
	ft_printf("mid = %d\n", mid);
	n_block = -1;
	while(stack->la > 1)
	{
		mid = find_median(stack->a, stack->la);
		n_block++;
		count_block[n_block] = 0;
		count_r = 0;
		while (stack->la - count_r >= 1)
		{
			if (stack->a[0] >= mid)
			{
				ps_ra(stack);
				count_r++;
			}
			else
			{
				ps_pb(stack);
				count_block[n_block]++;
			}
		}
	}
	while (n_block >= 0)
	{
		mid = find_median(stack->b, count_block[n_block]);
		ft_printf("mid = %d\n", mid);
		ft_printf("кол-во элементов в блоке = %d\n", count_block[n_block]);
		ft_printf("номер блока = %d\n", n_block);
		count_r = 0;
		while (count_block[n_block] - count_r > 0)
		{
			print_stack(stack);
			// if (count_block[n_block] == 1)
			// {
			// 	ps_pa(stack);
			// 	count_block[n_block]--;
			// }
			if (stack->b[0] >= mid)
			{
				ps_pa(stack);
				count_block[n_block]--;
			}
			else
			{
				ps_rb(stack);
				count_r++;
			}

			// if (stack->b[0] < mid)
			// {
			// 	ps_rb(stack);
			// 	count_r++;
			// }
			// else
			// {
			// 	ps_pa(stack);
			// 	count_block[n_block]--;
			// }
		}
		if (count_r)
		{
			while (count_r)
			{
				ps_rrb(stack);
				count_r--;
			}
		}
		else
		{
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
