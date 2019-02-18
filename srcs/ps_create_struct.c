/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:30:06 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/18 18:57:32 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create_new_stack(int len)
{
	t_stack	*stack;
	int		i;

	i = -1;
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	if (!(stack->a = (int *)malloc(sizeof(int) * len)))
		return (0);
	if (!(stack->b = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (++i < len)
		stack->b[i] = 0;
	stack->la = len;
	stack->lb = 0;
	return (stack);
}

t_draw		*create_new_draw()
{
	t_draw	*draw;
	char	*title;
	
	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		return (0);
	if (!(draw->mlx_ptr = (void *)malloc(sizeof(void))))
		return (0);
	if (!(draw->win_ptr = (void *)malloc(sizeof(void))))
		return (0);	
	title = ft_strdup("KK");
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window (draw->mlx_ptr, WIN_SIZE, WIN_SIZE, title);
	return (draw);
}

t_sd	*create_new_sd(t_stack *stack)
{
	t_sd	*sd;

	if (!(sd = (t_sd *)malloc(sizeof(t_sd))))
		return (0);
	sd->draw = create_new_draw();
	sd->stack = stack;
	sd->hight_line = WIN_SIZE / sd->stack->la;
	sd->width_one = (WIN_SIZE /2) / ft_intmax(sd->stack->a, sd->stack->la);
	return (sd);
}

int			del_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return (0);
}

int			ps_error(int *valid)
{
	write(2, "Error\n", 6);
	(*valid) = 0;
	return (0);
}
