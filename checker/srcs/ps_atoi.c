/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:09:31 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/08 14:40:37 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ps_error(t_stack *stack, int *valid)
{
	write(1, "error\n", 6);
	(*valid) = 0;
	del_stack(stack);
	return (0);
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
