/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:46 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/06 16:07:26 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **stack)
{
	int	max;

	if(is_sorted(*stack))
		return ;
	max = max_index(*stack);
	if ((*stack)->index == max)
		rotate_move(stack, NULL, "ra");
	else if ((*stack)->next->index == max)
		rotate_move(stack, NULL, "rra");
	if ((*stack)->index > (*stack)->next->index)
		swap_move(stack, NULL, "sa");
}

void	push_until3(t_stack **a, t_stack **b)
{
	int	len;
	int	i;
	int pushed;

	len = stack_len(*a);
	i = 0;
	pushed = 0;
	while (i < len)
	{
		if ((*a)->index <= len / 2)
			{
				swap_move(a, b, "pb");
				pushed++;
			}
		else
			rotate_move(a, NULL, "ra");
		i++;
	}
	while (len - pushed > 3)
	{
		swap_move(a, b, "pb");
		pushed++;
	}
	small_sort(a);
}
void	complex_sort(t_stack **a, t_stack **b)
{
	push_until3(a, b);
}
