/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:57:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/06 14:51:18 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define	FROM_A_TO_B 0
# define	FROM_B_TO_A 1
# define	CALL_BOTH	2

# include "libft.h"

void 	ps_swap(t_stack *stack, int len, int op);
void	ps_rotate(t_stack *stack, int len, int op);
void	ps_reverse_rotate(t_stack *stack, int len, int op);

typedef struct	s_cmd
{
	char		cmd[4];
	void		(*f)(t_stack *stack, int len, int op);
	char		type_args;
}				t_cmd;

typedef struct	s_stack
{
	int	*a;
	int *b;
}				t_stack;

t_cmd	g_ps_cmds[] = {
	{ "sa", ps_swap,	FROM_A_TO_B },
	// { "sb", ps_swap,	FROM_B_TO_A },
	// { "ss", ps_swap,	CALL_BOTH },
	// { "pa", ps_push,	FROM_B_TO_A },
	// { "pb", ps_push,	FROM_A_TO_B },
	{ "ra", ps_rotate,	FROM_A_TO_B },
	// { "rb", ps_rotate,	FROM_B_TO_A },
	// { "rr", ps_rotate,	CALL_BOTH },
	{ "rra", ps_reverse_rotate, FROM_A_TO_B },
	// { "rrb", ps_reverse_rotate, FROM_B_TO_A },
	// { "rrr", ps_reverse_rotate, CALL_BOTH },
	{ "", NULL, 0 }
};



#endif