/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:09:16 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/05 14:39:16 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}

void	swap(t_stack **stack)
{
	int temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*hold_top;
	t_stack	*hold_bottom;

	hold_top = *stack;
	*stack = (*stack)->next;
	hold_bottom = *stack;
	while (hold_bottom->next)
		hold_bottom = hold_bottom->next;
	hold_top->next = NULL;
	hold_bottom->next = hold_top;
}

void	reverse(t_stack **stack)
{
	t_stack *hold_top;
	t_stack *hold_bottom;
	t_stack *hold_last;

	hold_top = *stack;
	hold_bottom = *stack;
	while (hold_bottom->next->next)
		hold_bottom = hold_bottom->next;
	hold_last = hold_bottom;
	hold_last = hold_last->next;
	*stack = hold_last;
	hold_last->next = hold_top;
	hold_bottom->next = NULL;
}
