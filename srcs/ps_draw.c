/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:42:47 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 13:32:11 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	draw_back(t_sd *sd)
{
	int	x;
	int y;

	y = 0;
	while (y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE / 2)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_A);
		while (++x < WIN_SIZE)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_B);
		y++;
	}
}



void	draw_a(t_sd *sd, int start_pos_a)
{
	int y;
	int	x;
	int	ia;
	int	width_line;

	ia = 0;
	y =  start_pos_a;
	while (y < WIN_SIZE)
	{
		ft_printf("y %d\n", y);
		if (y > sd->hight_line * (ia + 1) + start_pos_a)
			ia++;
		width_line = sd->width_one * ABS(sd->stack->a[ia]);
		x = (WIN_SIZE / 2 - width_line) / 2;
		while (x < width_line + (WIN_SIZE / 2 - width_line) / 2)
		{
			if (sd->stack->a[ia] > 0)
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
			else
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
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
	int	width_line;

	ib = 0;
	y =  start_pos_b;
	while (y < WIN_SIZE)
	{
		if (y > sd->hight_line * (ib + 1) + start_pos_b)
			ib++;
		width_line = sd->width_one * ABS(sd->stack->b[ib]);
		x =  WIN_SIZE / 2 + ((WIN_SIZE / 2 - width_line) / 2);
		while (x < width_line + WIN_SIZE / 2 + ((WIN_SIZE / 2 - width_line) / 2)) // отрисовка линии
		{
			if (sd->stack->b[ib] > 0)
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
			else
				mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
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
	// y = MIN(start_pos_a, start_pos_b);
	// while (ia < sd->stack->la)
	// {
	// 	flag_a = 0;
	// 	flag_b = 0;
	// 	pos_y = -1;
	// 	while (++pos_y <= sd->hight_line)
	// 	{
	// 		// отрисовка стэка а
	// 		if (y > start_pos_a)
	// 		{
	// 			flag_a = 1;
	// 			width_line = sd->width_one * ABS(sd->stack->a[ia]);
	// 			x = (WIN_SIZE / 2 - width_line) / 2;
	// 			while (x < width_line + (WIN_SIZE / 2 - width_line) / 2) // отрисовка линии
	// 			{
	// 				if (sd->stack->a[ia] > 0)
	// 					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
	// 				else
	// 					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
	// 				x++;
	// 			}
	// 		}
	// 		// отрисовка стэка б
	// 		if (y > start_pos_b)
	// 		{
	// 			flag_b = 1;
	// 			width_line = sd->width_one * ABS(sd->stack->b[ib]);
	// 			x =  WIN_SIZE / 2 + ((WIN_SIZE / 2 - width_line) / 2);
	// 			while (x < width_line + WIN_SIZE / 2 + ((WIN_SIZE / 2 - width_line) / 2)) // отрисовка линии
	// 			{
	// 				if (sd->stack->b[ib] > 0)
	// 					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
	// 				else
	// 					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
	// 				x++;
	// 			}
	// 		}
	// 		y++;
	// 	}
	// 	if (flag_a)
	// 		ia++;
	// 	if (flag_b)
	// 		ib++;
	// }
}

int		ps_draw(t_sd *sd)
{
	char		*line;
	int 		valid;


	draw_back(sd);
	if (get_next_line(0, &line) == 1)
	{
		if (!call_cmd(sd->stack, line, &valid))
		{
			free(line);
			return (0);
		}
		if (line)
			free(line);
		visual_line(sd);
	}
	return (0);
}