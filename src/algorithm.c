/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:29:46 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/06 11:19:20 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_test(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(*a);
	while (i < len)
	{
		if ((*a)->index > len / 2)
			swap_move(a, b, "pb");
		else
			rotate_move(a, NULL, "ra");
		i++;
	}
	while (*a)
	{
		printf("a: %d\n", (*a)->value);
	}
	while (*b)
	{
		printf("b: %d\n", (*b)->value);
	}
	free_stack(a);
	free_stack(b);
	exit(0);
}
