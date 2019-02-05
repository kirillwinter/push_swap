/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/05 17:05:08 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char	*line;
	char	**vals;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(vals = (char **)malloc(sizeof(vals) * (argc))))
		return (0);
	while (j < argc)
	{
		vals[i] = ft_strdup(argv[j]);
		// ft_putendl(vals[i]);
		ft_putendl(vals[i]);
		i++;
		j++;
	}
	vals[i] = NULL;
	while (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		// *str[i] = *line;
		// i++;
		
		// free(line);
	}
	return (0);
}
