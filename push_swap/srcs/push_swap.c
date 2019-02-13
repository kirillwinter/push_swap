/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 13:54:05 by wballaba         ###   ########.fr       */
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
	int	count_block[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int	n_block;
	int len;
	int	sorted;

	n_block = -1;
	sorted = 0;
	len = stack->la;
	print_stack(stack, count_block, &n_block);
	first_sort(stack, count_block, &n_block, &sorted);
	while (sorted != len)
	{
		print_stack(stack, count_block, &n_block);
		sort_in_stack_b(stack, count_block, &n_block);
		print_stack(stack, count_block, &n_block);
		sort_in_stack_a(stack, count_block, &n_block, &sorted);
		if (count_block[n_block] == 0)
			n_block--;
	}
	print_stack(stack, count_block, &n_block);
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
