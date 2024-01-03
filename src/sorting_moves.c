/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:58:59 by gcampos-          #+#    #+#             */
/*   Updated: 2024/01/03 14:56:37 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rotate_move(a, b, "rrr");
	}
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_move(a, b, "rr");
	}
}

void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a < 0)
		{
			rotate_move(a, NULL, "rra");
			(*cost_a)++;
		}
		else if (*cost_a > 0)
		{
			rotate_move(a, NULL, "ra");
			(*cost_a)--;
		}
	}
}

void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_move(NULL, b, "rb");
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rotate_move(NULL, b, "rrb");
			(*cost_b)++;
		}
	}
}

void	pushing_to_a(t_stack **a, t_stack **b)
{
	t_stack	*sb;
	int		to_top_a;
	int		to_top_b;
	int		cheapest;

	sb = *b;
	cheapest = INT_MAX;
	while (sb)
	{
		if (absol(sb->to_top_a) + absol(sb->to_top_b) < absol(cheapest))
		{
			cheapest = absol(sb->to_top_a) + absol(sb->to_top_b);
			to_top_a = sb->to_top_a;
			to_top_b = sb->to_top_b;
		}
		sb = sb->next;
	}
	if (to_top_a < 0 && to_top_b < 0)
		reverse_both(a, b, &to_top_a, &to_top_b);
	else if (to_top_a > 0 && to_top_b > 0)
		rotate_both(a, b, &to_top_a, &to_top_b);
	rotate_a(a, &to_top_a);
	rotate_b(b, &to_top_b);
	swap_move(a, b, "pa");
}
