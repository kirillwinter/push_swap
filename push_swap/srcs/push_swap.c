/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/08 17:32:42 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	find_max_a(t_stack *stack)
// {
// 	int	max;
// 	int i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	max = stack->a[i];
// 	while(i < stack->la)
// 	{
// 		if (max < stack->a[i])
// 			max = stack->a[i];
// 		i++;
// 	}
// 	i = 0;
// 	ft_printf("max = %d\n", max);
// 	while (stack->a[0] != max) //кидаем в б все значения кроме мах
// 	{
// 		ps_pb(stack);
// 		i++;
// 	}
// 	ps_ra(stack); // кидаем вниз а мах
// 	while (max != stack->a[0])
// 	{
// 		ps_pb(stack);
// 		i++;
// 	}
	
	
// }

void	sort_kirilla_krasavchika(int *tmp, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int		find_median(t_stack *stack)
{
	int	tmp[stack->la];
	int	i;

	i = 0;
	while (i < stack->la)
	{
		tmp[i] = stack->a[i];
		i++;
	}
	i = 0;
	sort_kirilla_krasavchika(tmp, stack->la);
	return (tmp[stack->la / 2]);

}

int		sort_last_three(t_stack *stack)
{
	int	max;
	int i;

	i = 0;
	max = stack->a[i];
	while(i < 3)
	{
		if (max < stack->a[i])
			max = stack->a[i];
		i++;
	}
	i = 0;
	while (max != stack->a[i])
		i++;
	if (i == 0)
		ps_ra(stack);
	else if (i == 1)
		ps_rra(stack);
	if (stack->a[0] > stack->a[1])
		ps_sa(stack);
	return (0);
}

int		push_swap(t_stack *stack)
{
	int a;
	// while (stack->la > 3)
	// {
	// 	ps_pb(stack);
	// }
	// sort_last_three(stack);
	// find_max_a(stack);

	a = find_median(stack);
	ft_printf("mid = %d\n\n", a);
	print_stack(stack);
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		valid;

	g_count = 0;
	i = -1;
	valid = 1;
	stack = create_new_stack(argc - 1);
	while (++i < argc - 1)
	{
		stack->a[i] = ps_atoi(argv[i + 1], stack, &valid);
		check_сoincidence(stack, i, stack->a[i], &valid);
		if (!valid)
			return (0);
	}
	if (!push_swap(stack))
		return (0);
	check_vals(stack, i);
	del_stack(stack);
	return (1);
}
