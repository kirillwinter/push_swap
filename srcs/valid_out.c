/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:09:31 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/13 17:56:01 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_error(t_stack *stack, int *valid)
{
	write(1, "error\n", 6);
	(*valid) = 0;
	del_stack(stack);
	return (0);
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

// void	print_stack(t_stack *stack, int *count_block, int *n_block)
// {
// 	int i;

// 	i = 0;
// 	ft_printf("la = %d\n", stack->la);
// 	ft_printf("lb = %d\n", stack->lb);
// 	if ((*n_block) >= 0)
// 	{
// 		while (i < 6)
// 		{
// 			ft_printf("блок = %d\t", i);
// 			ft_printf("элементов = %d\n", count_block[i]);
// 			i++;
// 		}
// 	}
	
// 	i = 0;
// 	while (i < stack->la ||  i < stack->lb)
// 	{
// 		ft_printf("%d\t", stack->a[i]);
// 		ft_printf("%d\n", stack->b[i]);

// 		i++;
// 	}
// 	ft_printf("\n-----------------\n");
// 	ft_printf("a\tb\n");
// }

void	print_stack(t_stack *stack, int count_cmd)
{
	int i;

	i = 0;
	ft_printf("count_cmd = %d\n", count_cmd);
	ft_printf("la = %d\n", stack->la);
	ft_printf("lb = %d\n", stack->lb);
	while (i < stack->la ||  i < stack->lb)
	{
		if (i < stack->la)
			ft_printf("%d\t", stack->a[i]);
		else
			ft_printf("\t\t", stack->a[i]);
		if (i < stack->lb)
			ft_printf("%d\n", stack->b[i]);
		else
			ft_printf("\t\n", stack->a[i]);
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

static int	ps_valid_nbr(const char *str, t_stack *stack, int *valid)
{
	int i;

	i = 0;
	if (str[i] == '-' || (str[i] <= '9' && str[i] >= '0'))
	{
		if (str[i] == '-')
		{
			if (ft_strlen(str) <= 1)
				return (ps_error(stack, valid));
			i++;
		}
		while (str[i] != '\0')
		{
			if (str[i] > '9' || str[i] < '0')
				return (ps_error(stack, valid));
			i++;
		}
	}
	else
		return (ps_error(stack, valid));
	return (1);
	
}

int			ps_atoi(const char *str, t_stack *stack, int *valid)
{
	int			i;
	long int	nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (!ps_valid_nbr(str, stack, valid))
		return (0);
	if (str[i] == '-' && (str[i + 1] <= '9' && str[i + 1] >= '0'))
	{
		sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (nb < -2147483648 || nb > 2147483647)
			return (ps_error(stack, valid));
	}
	return (sign * nb);
}
