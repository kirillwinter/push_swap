/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:35:45 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 15:35:46 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALL_CMD_H
# define CALL_CMD_H

# include "push_swap.h"

const t_cmd	g_ps_cmds[] = {
	{ "sa", ps_swap,	FROM_A_TO_B },
	{ "sb", ps_swap,	FROM_B_TO_A },
	{ "ss", ps_swap,	CALL_BOTH },
	{ "pa", ps_pa,	FROM_B_TO_A },
	{ "pb", ps_pb,	FROM_A_TO_B },
	{ "ra", ps_ra,	FROM_A_TO_B },
	{ "rb", ps_rb,	FROM_B_TO_A },
	{ "rr", ps_rr,	CALL_BOTH },
	{ "rra", ps_rra, FROM_A_TO_B },
	{ "rrb", ps_rrb, FROM_B_TO_A },
	{ "rrr", ps_rrr, CALL_BOTH },
	{ "", NULL, 0 }
};

#endif