/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 16:22:29 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_median(int *arr, int len)
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

static int	push_swap(t_stack *stack)
{
	int	*count_block;
	int	n_block;
	int len;
	int	sorted;

	n_block = -1;
	sorted = 0;
	len = stack->la;
	count_block = ft_memalloc(999);
	first_sort(stack, count_block, &n_block, &sorted);
	while (sorted != len)
	{
		sort_b(stack, count_block, &n_block);
		sort_a(stack, count_block, &n_block, &sorted);
		if (count_block[n_block] == 0)
			n_block--;
	}
	free(count_block);
	return (1);
}

static int	read_one_arg_ps(char **argv)
{
	int		i;
	char	**vals;
	t_stack	*stack;
	int		len_vals;
	int		valid;

	i = -1;
	valid = 1;
	vals = ft_strsplit(argv[1], ' ');
	len_vals = ft_strcount((const char**)vals);
	stack = create_new_stack(len_vals);
	while (++i < len_vals)
	{
		stack->a[i] = ps_atoi(vals[i], &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (del_stack(stack));
	}
	if (!check_vals(stack, i, 0))
		push_swap(stack);
	del_stack(stack);
	return (1);
}

static int	read_many_arg_ps(int argc, char **argv)
{
	int		i;
	int		valid;
	t_stack	*stack;

	i = -1;
	valid = 1;
	stack = create_new_stack(argc - 1);
	while (++i < argc - 1)
	{
		stack->a[i] = ps_atoi(argv[i + 1], &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (del_stack(stack));
	}
	if (!check_vals(stack, i, 0))
		push_swap(stack);
	del_stack(stack);
	return (1);
}

int			main(int argc, char **argv)
{
	int	v;

	if (argc == 1)
		return (ps_error(&v));
	if (argc == 2)
	{
		if (!read_one_arg_ps(argv))
			return (0);
	}
	else
	{
		if (!read_many_arg_ps(argc, argv))
			return (0);
	}
	return (1);
}
