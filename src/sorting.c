/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:46:46 by gcampos-          #+#    #+#             */
/*   Updated: 2024/01/03 14:36:16 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lower_position(t_stack **a)
{
	t_stack	*tmp_a;
	int		lower;
	int		position;

	tmp_a = *a;
	lower = INT_MAX;
	stack_position(a);
	position = tmp_a->position;
	while (tmp_a)
	{
		if (tmp_a->index < lower)
		{
			lower = tmp_a->index;
			position = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (position);
}

void	last_sort(t_stack **a)
{
	int	len;
	int	lower;

	len = stack_len(*a);
	lower = lower_position(a);
	if (lower > len / 2)
	{
		while (lower++ < len)
			rotate_move(a, NULL, "rra");
	}
	else
	{
		while (lower--)
			rotate_move(a, NULL, "ra");
	}
}

void	small_sort(t_stack **stack)
{
	int	max;

	if (is_sorted(*stack))
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
	int	i;
	int	len;
	int	count;

	i = 0;
	len = stack_len(*a);
	count = len;
	while (i < len / 2)
	{
		if ((*a)->index <= len / 2)
		{
			swap_move(a, b, "pb");
			i++;
			count--;
		}
		else
			rotate_move(a, NULL, "ra");
	}
	while (count > 3)
	{
		swap_move(a, b, "pb");
		count--;
	}
	small_sort(a);
}

void	complex_sort(t_stack **a, t_stack **b)
{
	push_until3(a, b);
	while (*b)
	{
		closest_a(a, b);
		calculate_to_top(a, b);
		pushing_to_a(a, b);
	}
	if (!is_sorted(*a))
		last_sort(a);
}
