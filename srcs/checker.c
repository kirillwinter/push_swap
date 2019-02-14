/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/14 21:12:15 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	call_cmd(t_stack *stack, char *line, int *valid)
{
	if (!ft_strcmp(line, "sa"))
		ps_sa(stack, 0);
	else if (!ft_strcmp(line, "sb"))
		ps_sb(stack, 0);
	else if (!ft_strcmp(line, "ss"))
		ps_ss(stack, 0);
	else if (!ft_strcmp(line, "pa"))
		ps_pa(stack, 0);
	else if (!ft_strcmp(line, "pb"))
		ps_pb(stack, 0);
	else if (!ft_strcmp(line, "ra"))
		ps_ra(stack, 0);
	else if (!ft_strcmp(line, "rb"))
		ps_rb(stack, 0);
	else if (!ft_strcmp(line, "rr"))
		ps_rr(stack, 0);
	else if (!ft_strcmp(line, "rra"))
		ps_rra(stack, 0);
	else if (!ft_strcmp(line, "rrb"))
		ps_rrb(stack, 0);
	else if (!ft_strcmp(line, "rrr"))
		ps_rrr(stack, 0);
	else
		return (ps_error(valid));
	return (1);
}

static int	read_instructions(t_stack *stack, int *valid, int v)
{
	char	*line;
	int		count_cmd;

	count_cmd = 0;
	if (v == 2)
		print_stack(stack, count_cmd);
	while (get_next_line(0, &line) == 1)
	{
		if (!call_cmd(stack, line, valid))
			return (0);
		if (v == 2)
		{
			count_cmd++;
			print_stack(stack, count_cmd);
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
	check_vals(stack, i);
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
	check_vals(stack, i);
	del_stack(stack);
	return (1);
}

int			main(int argc, char **argv)
{
	int		v;

	v = 1;
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
