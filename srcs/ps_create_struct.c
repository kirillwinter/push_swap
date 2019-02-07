/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:30:06 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 19:46:46 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_stack(int len)
{
	t_stack	*stack;
	int	i;

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

// t_cmd	*create_cmd()
// {
// 	t_cmd *cmd;

// 	if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd) * 12)))
// 		return (0);
	

// 	cmd[0] = {"sa", ps_sa};

// 	cmd = {
// 		{ "sa", ps_sa },
// 		{ "sb", ps_sb },
// 		{ "ss", ps_ss },
// 		{ "pa", ps_pa },
// 		{ "pb", ps_pb },
// 		{ "ra", ps_ra },
// 		{ "rb", ps_rb },
// 		{ "rr", ps_rr },
// 		{ "rra", ps_rra },
// 		{ "rrb", ps_rrb },
// 		{ "rrr", ps_rrr },
// 		{ "", NULL }
// 	};
// 	return (cmd);
// }