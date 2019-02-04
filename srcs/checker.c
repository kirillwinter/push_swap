/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:55:07 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/04 21:51:59 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	char s1[] = "hello kirill";
	char s2[] = "a";

	ft_printf("%s\n", strpbrk(s1, s2));
	ft_printf("%s\n", ft_strpbrk(s1, s2));
	ft_printf("HELLO WORLD\n");
	return (0);
}