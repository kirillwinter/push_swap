/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/06 14:58:47 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ps_reverse_rotate(t_stack *stack, int len, int op)
{
	int	tmp[len - 1];
	int	vals[len - 1];
	int i;
	int	j;

	i = 0;
	j = 0;
	// if (g_ps_cmds[op].type_args == 0)

	tmp[j] = vals[len - 1];
	j++;
	while (j < len)
	{
		tmp[j] = vals[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len)
	{
		vals[i] = tmp[i];
		i++;
	}
}

void	ps_rotate(t_stack *stack, int len, int op)
{
	int	tmp[len - 1];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[len - 1] = vals[i];
	i++;
	while (i < len)
	{
		tmp[j] = vals[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len)
	{
		vals[i] = tmp[i];
		i++;
	}
}

void	ps_swap(t_stack *stack, int len, int op)
{
	if (g_ps_cmds[op].type_args == 0)
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (g_ps_cmds[op].type_args == 1)
		ft_swap(&stack->b[0], &stack->b[1]);
	else
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_swap(&stack->b[0], &stack->b[1]);
	}
}

int		check_vals(t_stack *stack, int len)
{
	int i;

	i = 0;
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

	while (get_next_line(0, &line) == 1)
	{
		i = 0;
		while (i < 11)
		{
			if (!ft_strcmp(line, g_ps_cmds[i].cmd))
				g_ps_cmds[i].f(stack, len);
			i++;
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		vals[argc - 1];
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	j = 1;
	while (j < argc)
	{
		stack->a[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	read_instruchtions(stack, i);
	j = 0;
	while (j < i)
	{
		ft_printf("%d ", vals[j]);
		j++;
	}
	ft_printf("\n");
	check_vals(vals, i);

	return (0);
}
