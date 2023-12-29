/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:58:59 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/29 21:17:41 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rotate_move(a, b, "rrr");
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_move(a, b, "rr");
	}
}

static void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a < 0)
		{
			(*cost_a)++;
			rotate_move(a, NULL, "rra");
		}
		else if (*cost_a > 0)
		{
			(cost_a)--;
			rotate_move(a, NULL, "ra");
		}
	}
}

static void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b < 0)
		{
			(*cost_b)++;
			rotate_move(NULL, b, "rrb");
		}
		else if (*cost_b > 0)
		{
			(cost_b)--;
			rotate_move(NULL, b, "rb");
		}
	}
}

void	pushing_to_a(t_stack **a, t_stack **b)
{
	printf("will start pushing_to_a\n");
	t_stack	*sb;
	int		to_top_a;
	int		to_top_b;
	int		cheapest;

	sb = *b;
	while (sb)
	{
		printf("sb->value = %d\n", sb->value);
		printf("sb->index = %d\n", sb->index);
		sb = sb->next;
	}
	printf("reach here\n");
	sb = *b;
	cheapest = INT_MAX;
	while (sb)
	{
		printf("entering pushing_to_a\n");
		printf("sb->to_top_a = %d\n", sb->to_top_a);
		printf("sb->to_top_b = %d\n", sb->to_top_b);
		if (absolute(sb->to_top_a) + absolute(sb->to_top_b) < absolute(cheapest))
		{
			cheapest = absolute(sb->to_top_a) + absolute(sb->to_top_b);
			printf("cheapest = %d\n", cheapest);
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
