/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:38:02 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 15:40:42 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_back(t_sd *sd)
{
	int	x;
	int y;

	y = 0;
	while (y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE / 2)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, BACK_A);
		while (++x < WIN_SIZE)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, BACK_B);
		y++;
	}
}

void	draw_a(t_sd *sd, int start_pos_a)
{
	int y;
	int	x;
	int	ia;
	int	wid_line;

	ia = 0;
	y = start_pos_a;
	while (y < WIN_SIZE)
	{
		if (y > sd->hight_line * (ia + 1) + start_pos_a)
			ia++;
		wid_line = sd->width_one * ABS(sd->stack->a[ia]);
		x = (WIN_SIZE / 2 - wid_line) / 2;
		while (x < wid_line + (WIN_SIZE / 2 - wid_line) / 2)
		{
			if (sd->stack->a[ia] > 0)
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, POS);
			else
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, NEG);
			x++;
		}
		y++;
	}
}

void	draw_b(t_sd *sd, int start_pos_b)
{
	int y;
	int	x;
	int	ib;
	int	wid_line;

	ib = 0;
	y = start_pos_b;
	while (y < WIN_SIZE)
	{
		if (y > sd->hight_line * (ib + 1) + start_pos_b)
			ib++;
		wid_line = sd->width_one * ABS(sd->stack->b[ib]);
		x = WIN_SIZE / 2 + ((WIN_SIZE / 2 - wid_line) / 2);
		while (x < wid_line + WIN_SIZE / 2 + ((WIN_SIZE / 2 - wid_line) / 2))
		{
			if (sd->stack->b[ib] > 0)
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, POS);
			else
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, NEG);
			x++;
		}
		y++;
	}
}

void	visual_line(t_sd *sd)
{
	int	start_pos_a;
	int	start_pos_b;

	start_pos_a = WIN_SIZE - sd->stack->la * sd->hight_line;
	start_pos_b = WIN_SIZE - sd->stack->lb * sd->hight_line;
	draw_back(sd);
	draw_a(sd, start_pos_a);
	draw_b(sd, start_pos_b);
}
