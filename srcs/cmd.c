/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:45:24 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/07 13:45:25 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *stack, int op)
{
	if (op == 0 && stack->la >= 2)
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (op == 1 && stack->lb >= 2)
		ft_swap(&stack->b[0], &stack->b[1]);
	else if (op == 2 && stack->la >= 2 && stack->lb >= 2)
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_swap(&stack->b[0], &stack->b[1]);
	}
}

void	ps_pa(t_stack *stack, int op)
{
	int	tmp[9999];
	int	push;
	int i;

	i = -1;
	if (!stack->lb)
		return ;
	push = stack->b[0];
	while (++i < stack->la)
		tmp[i] = stack->a[i];
	i = -1;
	stack->a[0] = push;
	while (++i < stack->la)
		stack->a[i + 1] = tmp[i];
	stack->la++;
	i = -1;
	while (++i < stack->lb)
		stack->b[i] = stack->b[i + 1];
	stack->lb--;
}

void	ps_pb(t_stack *stack, int op)
{
	int	tmp[9999];
	int	push;
	int i;

	i = -1;
	if (!stack->la)
		return ;
	push = stack->a[0];
	while (++i < stack->lb)
		tmp[i] = stack->b[i];
	i = -1;
	stack->b[0] = push;
	while (++i < stack->lb)
		stack->b[i + 1] = tmp[i];
	stack->lb++;
	i = -1;
	while (++i < stack->la)
		stack->a[i] = stack->a[i + 1];
	stack->la--;
}

void	ps_ra(t_stack *stack, int op)
{
	int	tmp[stack->la];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[stack->la - 1] = stack->a[i];
	i++;
	while (i < stack->la)
	{
		tmp[j] = stack->a[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->la)
	{
		stack->a[i] = tmp[i];
		i++;
	}
}

void	ps_rb(t_stack *stack, int op)
{
	int	tmp[stack->lb];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[stack->lb - 1] = stack->b[i];
	i++;
	while (i < stack->lb)
	{
		tmp[j] = stack->b[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->lb)
	{
		stack->b[i] = tmp[i];
		i++;
	}
}

void	ps_rr(t_stack *stack, int op)
{
	ps_ra(stack, op);
	ps_ra(stack, op);
}


void	ps_rra(t_stack *stack,  int op)
{
	int	tmp[stack->la];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[j] = stack->a[stack->la - 1];
	j++;
	while (j < stack->la)
	{
		tmp[j] = stack->a[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->la)
	{
		stack->a[i] = tmp[i];
		i++;
	}
}

void	ps_rrb(t_stack *stack,  int op)
{
	int	tmp[stack->lb];
	int i;
	int	j;

	i = 0;
	j = 0;
	tmp[j] = stack->b[stack->lb - 1];
	j++;
	while (j < stack->lb)
	{
		tmp[j] = stack->b[i];
		i++;
		j++;
	}
	i = 0;
	while (i < stack->lb)
	{
		stack->b[i] = tmp[i];
		i++;
	}
}

void	ps_rrr(t_stack *stack, int op)
{
	ps_rra(stack, op);
	ps_rrb(stack, op);
}
