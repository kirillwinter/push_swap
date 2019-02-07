/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 13:36:00 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "call_cmd.h"

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
	while (i <= len)
	{
		if (i < len)
		{
			if (stack->a[i] > stack->a[i + 1])
			{
				write(1, "KO\n", 3);
				return (0);
			}
		}
		else
		{
			write(1, "OK\n", 3);
			return (1);
		}
		i++;
	}
	return (0);
}

int		read_instruchtions(t_stack *stack, int len)
{
	char	*line;
	int		i;

	stack->la = len;
	stack->lb = 0;
	while (get_next_line(0, &line) == 1)
	{
		i = 0;
		while (i < 11)
		{
			if (!ft_strcmp(line, g_ps_cmds[i].cmd))
			{
				g_ps_cmds[i].f(stack, g_ps_cmds[i].type_args);
				print_stack(stack);
			}
			i++;
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = -1;
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	while (++i < argc -1)
		stack->a[i] = ft_atoi(argv[i + 1]);
	read_instruchtions(stack, i);
	check_vals(stack, i);

	return (0);
}
