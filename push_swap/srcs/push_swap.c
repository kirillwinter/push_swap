/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/11 15:18:29 by wballaba         ###   ########.fr       */
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

int		push_swap(t_stack *stack)
{
	int mid;
	int	count_r;
	int	count_block[] = {0, 0, 0, 0, 0, 0};
	int	n_block;

	n_block = -1;
	print_stack(stack);
	while(stack->la > 3)
		sort_in_stack_a(stack, count_block, &n_block);
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
			sort_in_stack_b(stack, count_block, &n_block);
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
