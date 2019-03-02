/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/03/01 16:54:29 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_instructions(t_stack *stack, int *valid, int v)
{
	char		*line;
	t_sd		*sd;

	if (v == 2)
	{
		sd = create_new_sd(stack);
		visual_line(sd);
		mlx_loop_hook(sd->draw->mlx_ptr, ps_draw, sd);
		mlx_loop(sd->draw->mlx_ptr);
	}
	else
	{
		while (get_next_line(0, &line) == 1)
		{
			if (!call_cmd(stack, line, valid))
			{
				free(line);
				return (0);
			}
			if (line)
				free(line);
		}
	}
	return (1);
}

static int	read_one_arg_checker(char **argv, int v)
{
	int		i;
	char	**vals;
	t_stack	*stack;
	int		len_vals;
	int		valid;

	i = -1;
	valid = 1;
	vals = ft_strsplit(argv[v], ' ');
	len_vals = ft_strcount((const char**)vals);
	stack = create_new_stack(len_vals);
	while (++i < len_vals)
	{
		stack->a[i] = ps_atoi(vals[i], &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (del_stack(stack));
	}
	if (!read_instructions(stack, &valid, v))
		return (del_stack(stack));
	check_vals(stack, i, 1);
	del_stack(stack);
	return (1);
}

static int	read_many_arg_checker(int argc, char **argv, int v)
{
	int		i;
	int		valid;
	t_stack	*stack;

	i = -1;
	valid = 1;
	stack = create_new_stack(argc - v);
	while (++i < argc - v)
	{
		stack->a[i] = ps_atoi(argv[i + v], &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (del_stack(stack));
	}
	if (!read_instructions(stack, &valid, v))
		return (del_stack(stack));
	check_vals(stack, i, 1);
	del_stack(stack);
	return (1);
}

int			main(int argc, char **argv)
{
	int		v;

	v = 1;
	if (argc == 1)
		return (ps_error(&v));
	if (argc > 1 && !ft_strcmp(argv[1], "-v"))
	{
		v++;
		if (argc == 3)
			read_one_arg_checker(argv, v);
		else
			read_many_arg_checker(argc, argv, v);
	}
	else
	{
		if (argc == 2)
			read_one_arg_checker(argv, v);
		else
			read_many_arg_checker(argc, argv, v);
	}
	return (1);
}
