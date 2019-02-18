/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:42:47 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/18 21:11:01 by wballaba         ###   ########.fr       */
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

void	visual_line(t_sd *sd, int len)
{
	int	x;
	int y;
	int ia;
	int ib;
	int	pos_y;
	int	pos_x;
	// int	nbr_line;
	int	width_line;
	int	start_pos_a;
	int	start_pos_b;
	int	flag_a;
	int	flag_b;
	
	y = 0;
	ia = 0;
	ib = 0;
	start_pos_a = WIN_SIZE - sd->stack->la * sd->hight_line;
	start_pos_b = WIN_SIZE - sd->stack->lb * sd->hight_line;
	len = 0;
 	// while (y < len - MAX(sd->stack->la, sd->stack->lb)) // отрисовка фона до первой линии
	while (y < MIN(start_pos_a, start_pos_b))
	{
		x = -1;
		while (++x < WIN_SIZE / 2)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_A);
		while (++x < WIN_SIZE)
			mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_B);
		y++;
	}
	ft_printf("hight_line %d\n", sd->hight_line);
	ft_printf("width_one %d\n", sd->width_one);
	ft_printf("start_pos_a %d\n", start_pos_a);
	ft_printf("start_pos_b %d\n", start_pos_b);
	while (y < WIN_SIZE)
	{
		flag_a = 0;
		flag_b = 0;
		pos_y = -1;
		while (++pos_y <= sd->hight_line)
		{
			// отрисовка стэка а
			if (y > start_pos_a)
			{
				flag_a = 1;
				width_line = sd->width_one * ABS(sd->stack->a[ia]);
				x = -1;
				while (++x < (WIN_SIZE / 2 - width_line) / 2 ) // отступ от левого края до начала линни
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_A);
				pos_x = -1;
				while (++pos_x < width_line) // отрисовка линии
				{
					if (sd->stack->a[ia] > 0)
						mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
					else
						mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
					x++;
				}
				while (++x < WIN_SIZE / 2) // отрисовка фона после линии до стэка б
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_A);
			}
			else
			{
				while (++x < WIN_SIZE / 2)
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_A);
			}
			// отрисовка стэка б
			if (y > start_pos_b)
			{
				flag_b = 1;
				width_line = sd->width_one * ABS(sd->stack->b[ib]);
				while (++x < WIN_SIZE / 2 + ((WIN_SIZE / 2 - width_line) / 2)) // отступ от левого края до начала линни
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_B);
				pos_x = -1;
				while (++pos_x < width_line) // отрисовка линии
				{
					if (sd->stack->b[ib] > 0)
						mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_POSITIV);
					else
						mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_NEGATIV);
					x++;
				}
				while (++x < WIN_SIZE) // отрисовка фона после линии до стэка б
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_B);
			}
			else
			{
				while (++x < WIN_SIZE)
					mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, x, y, D_BACK_B);
			}
			y++;
		}
		if (flag_a)
			ia++;
		if (flag_b)
			ib++;
	}
}

int		ps_draw(t_sd *sd)
{
	char		*line;
	int			len;
	// int			count_cmd;
	// char 		*str;
	int 		valid;

	// str = ft_itoa(count_cmd);

	len = sd->stack->la;
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
		visual_line(sd, len);
		// mlx_string_put(sd->draw->mlx_ptr, sd->draw->win_ptr, 250, 250, 0xFFFFFF, str);	

		// mlx_pixel_put(sd->draw->mlx_ptr, sd->draw->win_ptr, 250, 250, 0xFFFFFF);
	}
	return (0);
}