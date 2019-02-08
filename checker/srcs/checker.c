/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/08 14:38:38 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *stack)
{
	int i;

	i = 0;
	ft_printf("la = %d\n", stack->la);
	ft_printf("lb = %d\n", stack->lb);
	while (i < stack->la ||  i < stack->lb)
	{
		ft_printf("%d\t", stack->a[i]);
		ft_printf("%d\n", stack->b[i]);
		i++;
	}
	ft_printf("\n---------\n");
	ft_printf("a\tb\n");
}

int		check_vals(t_stack *stack, int len)
{
	int i;

	i = 0;
	if (stack->la != len)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	while (i < len - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			write(1, "KO\n", 3);
			return (0);
		}
		i++;
	}
	write(1, "OK\n", 3);
	return (1);
}

// int		read_instructions(t_stack *stack)
// {
// 	char	*line;
// 	int		i;
// 	t_cmd *cmd;

// 	cmd = create_cmd();
// 	while (get_next_line(0, &line) == 1)
// 	{
// 		if (!ft_strcmp(line, cmd[i].cmd))
// 			cmd[i].f(stack);
// 				print_stack(stack);
// 			}
// 			i++;
// 		}
// 	}
// 	return (1);
// }

int		read_instructions(t_stack *stack, int *valid)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "sa"))
			ps_sa(stack);
		else if (!ft_strcmp(line, "sb"))
			ps_sb(stack);
		else if (!ft_strcmp(line, "ss"))
			ps_ss(stack);
		else if (!ft_strcmp(line, "pa"))
			ps_pa(stack);
		else if (!ft_strcmp(line, "pb"))
			ps_pb(stack);
		else if (!ft_strcmp(line, "ra"))
			ps_ra(stack);
		else if (!ft_strcmp(line, "rb"))
			ps_rb(stack);
		else if (!ft_strcmp(line, "rr"))
			ps_rr(stack);
		else if (!ft_strcmp(line, "rra"))
			ps_rra(stack);
		else if (!ft_strcmp(line, "rrb"))
			ps_rrb(stack);
		else if (!ft_strcmp(line, "rrr"))
			ps_rrr(stack);
		else
			return (ps_error(stack, valid));		
		print_stack(stack);		
	}
	return (1);
}

int	check_сoincidence(t_stack *stack, int len, int val, int *valid)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stack->a[i] == val)
			return (ps_error(stack, valid));
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		valid;

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
	if (!read_instructions(stack, &valid))
		return (0);
	check_vals(stack, i);
	del_stack(stack);
	return (1);
}
