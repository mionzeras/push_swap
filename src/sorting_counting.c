/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_counting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:22:15 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/29 21:20:11 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_a(t_stack **a, int b_index, int max, int a_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < max)
		{
			max = tmp_a->index;
			a_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (max != INT_MAX)
		return (a_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < max)
		{
			max = tmp_a->index;
			a_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (a_pos);
}

void	stack_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

void	closest_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		a_pos;

	tmp_b = *b;
	stack_position(a);
	stack_position(b);
	a_pos = 0;
	while (tmp_b)
	{
		a_pos = target_a(a, tmp_b->index, INT_MAX, a_pos);
		tmp_b->where_put_a = a_pos;
		tmp_b = tmp_b->next;
	}
}

void	calculate_to_top(t_stack **a, t_stack **b)
{
	t_stack	*sa;
	t_stack	*sb;
	int		size_a;
	int		size_b;

	sa = *a;
	sb = *b;
	size_a = stack_len(sa);
	size_b = stack_len(sb);
	printf("reach here\n");
	while (sb)
	{
		sb->to_top_b = sb->position;
		if (sb->position > size_b / 2)
			sb->to_top_b = (size_b - sb->position) * -1;
		sb->to_top_a = sb->where_put_a;
		if (sb->where_put_a > size_a / 2)
			sb->to_top_a = (size_a - sb->where_put_a) * -1;
		sb = sb->next;
	}
}
