/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:29:46 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/05 15:21:48 by gcampos-         ###   ########.fr       */
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
			push(a, b);
		//else
			//rotate_move(a, b, "ra");
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
