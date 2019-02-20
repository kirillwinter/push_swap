/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:59:41 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 15:32:09 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_cmd(t_stack *stack, char *line, int *valid)
{
	if (!ft_strcmp(line, "sa"))
		ps_sa(stack, 0);
	else if (!ft_strcmp(line, "sb"))
		ps_sb(stack, 0);
	else if (!ft_strcmp(line, "ss"))
		ps_ss(stack, 0);
	else if (!ft_strcmp(line, "pa"))
		ps_pa(stack, 0);
	else if (!ft_strcmp(line, "pb"))
		ps_pb(stack, 0);
	else if (!ft_strcmp(line, "ra"))
		ps_ra(stack, 0);
	else if (!ft_strcmp(line, "rb"))
		ps_rb(stack, 0);
	else if (!ft_strcmp(line, "rr"))
		ps_rr(stack, 0);
	else if (!ft_strcmp(line, "rra"))
		ps_rra(stack, 0);
	else if (!ft_strcmp(line, "rrb"))
		ps_rrb(stack, 0);
	else if (!ft_strcmp(line, "rrr"))
		ps_rrr(stack, 0);
	else
		return (ps_error(valid));
	return (1);
}
