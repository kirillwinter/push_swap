/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:09:31 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 14:41:08 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_сoincidence(t_stack *stack, int len, int val, int *valid)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stack->a[i] == val)
			return (ps_error(valid));
		i++;
	}
	return (1);
}

int			ps_error(int *valid)
{
	write(2, "Error\n", 6);
	(*valid) = 0;
	return (0);
}

int			check_vals(t_stack *stack, int len, int checker)
{
	int i;

	i = 0;
	if (checker == 1)
	{
		if (stack->la != len)
		{
			write(1, "KO\n", 3);
			return (0);
		}
	}
	while (i < len - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			if (checker == 1)
				write(1, "KO\n", 3);
			return (0);
		}
		i++;
	}
	if (checker == 1)
		write(1, "OK\n", 3);
	return (1);
}

static int	ps_valid_nbr(const char *str, int *valid)
{
	int i;

	i = 0;
	if (str[i] == '-' || (str[i] <= '9' && str[i] >= '0'))
	{
		if (str[i] == '-')
		{
			if (ft_strlen(str) <= 1)
				return (ps_error(valid));
			i++;
		}
		while (str[i] != '\0')
		{
			if (str[i] > '9' || str[i] < '0')
				return (ps_error(valid));
			i++;
		}
	}
	else
		return (ps_error(valid));
	return (1);
}

int			ps_atoi(const char *str, int *valid)
{
	int			i;
	long long	nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (!ps_valid_nbr(str, valid))
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
		if ((nb > 2147483648 && sign == -1) || (nb > 2147483647 && sign == 1))
			return (ps_error(valid));
	}
	return (sign * nb);
}
