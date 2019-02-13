/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 18:06:49 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "checker.h"
#include "push_swap.h"

int		read_instructions(t_stack *stack, int *valid, int v)
{
	char	*line;
	int		count_cmd;

	count_cmd = 0;
	while (get_next_line(0, &line) == 1)
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
			return (ps_error(stack, valid));
		if (v == 1)
		{
			count_cmd++;
			print_stack(stack, count_cmd);
		}
			
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		valid;
	int		v;

	i = -1;
	valid = 1;
	v = 0;
	if (argc > 1 && !ft_strcmp(argv[1], "-v"))
	{
		v = 1;
		stack = create_new_stack(argc - 2);
		i++;
	}
	else
		stack = create_new_stack(argc - 1);
	while (++i < argc - 1)
	{
		stack->a[i] = ps_atoi(argv[i + 1], stack, &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (0);
	}
	if (!read_instructions(stack, &valid, v))
		return (0);
	check_vals(stack, i);
	// del_stack(stack);
	return (1);
}
