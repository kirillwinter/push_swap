/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:57:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 20:17:30 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stack
{
	int	*a;
	int *b;
	int	la;
	int	lb;
}				t_stack;

void	ps_sa(t_stack *stack);
void	ps_sb(t_stack *stack);
void	ps_ss(t_stack *stack);
void	ps_pa(t_stack *stack);
void	ps_pb(t_stack *stack);
void	ps_ra(t_stack *stack);
void	ps_rb(t_stack *stack);
void	ps_rr(t_stack *stack);
void	ps_rra(t_stack *stack);
void	ps_rrb(t_stack *stack);
void	ps_rrr(t_stack *stack);

typedef struct	s_cmd
{
	char		cmd[4];
	void		(*f)(t_stack *stack);
}				t_cmd;

t_stack	*create_new_stack(int len);
int		ps_atoi(const char *str, int *valid);
// t_cmd	*create_cmd();

#endif