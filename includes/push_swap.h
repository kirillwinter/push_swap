/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:57:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/19 18:59:30 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define WIN_SIZE 500
# define BACK_A 0x1049A9
# define BACK_B 0x29497F
# define POS 0x4479D4
# define NEG 0x6A92D4

# include "libft.h"
# include "mlx.h"

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			la;
	int			lb;
}				t_stack;

typedef struct	s_draw
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_draw;

typedef struct	s_sd
{
	t_draw		*draw;
	t_stack		*stack;
	int			hight_line;
	int			width_one;
	int			len;
}				t_sd;

void			ps_sa(t_stack *stack, int print);
void			ps_sb(t_stack *stack, int print);
void			ps_ss(t_stack *stack, int print);
void			ps_pa(t_stack *stack, int print);
void			ps_pb(t_stack *stack, int print);
void			ps_ra(t_stack *stack, int print);
void			ps_rb(t_stack *stack, int print);
void			ps_rr(t_stack *stack, int print);
void			ps_rra(t_stack *stack, int print);
void			ps_rrb(t_stack *stack, int print);
void			ps_rrr(t_stack *stack, int print);

int				call_cmd(t_stack *stack, char *line, int *valid);
t_stack			*create_new_stack(int len);

t_draw			*create_new_draw(void);
t_sd			*create_new_sd(t_stack *stack);
int				ps_draw(t_sd *sd);
int				del_sd(t_sd	*sd);

int				del_stack(t_stack *stack);
int				ps_atoi(const char *str, int *valid);
int				ps_error(int *valid);
int				check_vals(t_stack *stack, int len, int checker);

int				check_сoincidence(t_stack *stack, int len, int val, int *valid);

int				find_median(int *arr, int len);

void			first_sort(t_stack *stack, int *count_block, int *n_block,\
				int *sorted);
void			sort_top_three_a(t_stack *stack);

void			sort_a(t_stack *stack, int *count_block, int *n_block,\
				int *sorted);
int				check_move_val_a(int *arr, int len, int mid);

void			sort_b(t_stack *stack, int *count_block, int *n_block);

void			visual_line(t_sd *sd);

#endif
