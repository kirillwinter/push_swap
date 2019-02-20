/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:30:06 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 15:35:04 by wballaba         ###   ########.fr       */
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

t_draw		*create_new_draw(void)
{
	t_draw	*draw;

	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		return (0);
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window(draw->mlx_ptr, WIN_SIZE, WIN_SIZE, "KK");
	return (draw);
}

t_sd		*create_new_sd(t_stack *stack)
{
	t_sd	*sd;

	if (!(sd = (t_sd *)malloc(sizeof(t_sd))))
		return (0);
	sd->draw = create_new_draw();
	sd->stack = stack;
	sd->len = sd->stack->la;
	sd->hight_line = WIN_SIZE / sd->stack->la;
	sd->width_one = (WIN_SIZE / 2) / ft_intmaxabs(sd->stack->a, sd->stack->la);
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

int			del_sd(t_sd *sd)
{
	if (sd->draw)
		free(sd->draw);
	if (sd)
		free(sd);
	return (0);
}
