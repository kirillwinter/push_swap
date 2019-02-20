/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:42:47 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 16:19:32 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_draw_check(t_sd *sd)
{
	check_vals(sd->stack, sd->len, 1);
	del_sd(sd);
	del_stack(sd->stack);
	exit(1);
}

int		ps_draw(t_sd *sd)
{
	char	*line;
	int		valid;
	int		len;

	len = sd->stack->la;
	valid = 1;
	if (get_next_line(0, &line) == 1)
	{
		if (!call_cmd(sd->stack, line, &valid))
		{
			free(line);
			mlx_destroy_window(sd->draw->mlx_ptr, sd->draw->win_ptr);
			del_sd(sd);
			del_stack(sd->stack);
			exit(0);
		}
		if (line)
			free(line);
		visual_line(sd);
	}
	else
		ps_draw_check(sd);
	return (1);
}
