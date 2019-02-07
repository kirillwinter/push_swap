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

typedef struct	s_stack
{
	int	a[9999];
	int b[9999];
	int	la;
	int	lb;
}				t_stack;

void 	ps_swap(t_stack *stack, int op);
void	ps_pa(t_stack *stack, int op);
void	ps_pb(t_stack *stack, int op);
void	ps_ra(t_stack *stack, int op);
void	ps_rb(t_stack *stack, int op);
void	ps_rr(t_stack *stack, int op);
void	ps_rra(t_stack *stack, int op);
void	ps_rrb(t_stack *stack, int op);
void	ps_rrr(t_stack *stack, int op);

typedef struct	s_cmd
{
	char		cmd[4];
	void		(*f)(t_stack *stack, int op);
	char		type_args;
}				t_cmd;



#endif