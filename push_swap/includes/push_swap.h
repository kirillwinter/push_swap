/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:57:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/12 15:53:53 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stack
{
	int				*a;
	int				*b;
	int				la;
	int				lb;
}					t_stack;

// typedef struct	s_block
// {
// 	int				a;
// 	int				b;
// 	int				sum;
// 	int				n_blcok;
// 	struct s_block	*next;
// }				t_block;

int				g_count;
int				g_sorted;

void			ps_sa(t_stack *stack);
void			ps_sb(t_stack *stack);
void			ps_ss(t_stack *stack);
void			ps_pa(t_stack *stack);
void			ps_pb(t_stack *stack);
void			ps_ra(t_stack *stack);
void			ps_rb(t_stack *stack);
void			ps_rr(t_stack *stack);
void			ps_rra(t_stack *stack);
void			ps_rrb(t_stack *stack);
void			ps_rrr(t_stack *stack);

typedef struct	s_cmd
{
	char		cmd[4];
	void		(*f)(t_stack *stack);
}				t_cmd;

t_stack			*create_new_stack(int len);
void			del_stack(t_stack *stack);
int				ps_atoi(const char *str, t_stack *stack, int *valid);
int				ps_error(t_stack *stack, int *valid);
int				check_vals(t_stack *stack, int len);
void			print_stack(t_stack *stack, int *count_block, int *n_block);
int				check_сoincidence(t_stack *stack, int len, int val, int *valid);

int				find_median(int *arr, int len);

void			first_sort_in_stack_a(t_stack *stack, int *count_block, int *n_block);
void			sort_in_stack_a(t_stack *stack, int *count_block, int *n_block);
void			sort_top_three_a(t_stack *stack);
void			sort_last_three_a(t_stack *stack);


void			sort_in_stack_b(t_stack *stack, int *count_block, int *n_block);

void	sort(t_stack *stack, int *count_block, int *n_block);

#endif
