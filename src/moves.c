/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:41:15 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/06 15:50:20 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(t_stack **a, t_stack **b, char *choice)
{
	if (choice[0] == 's' && choice[1] == 'a')
		swap(a);
	else if (choice[0] == 's' && choice[1] == 'b')
		swap(b);
	else if (choice[0] == 's' && choice[1] == 's')
	{
		swap(a);
		swap(b);
	}
	if (choice[0] == 'p' && choice[1] == 'a')
		push(b, a);
	else if (choice[0] == 'p' && choice[1] == 'b')
		push(a, b);
	ft_putstr(choice);
	ft_putstr("\n");
}

void	rotate_move(t_stack **a, t_stack **b, char *choice)
{
	if (choice[0] == 'r' && choice[1] == 'a')
		rotate(a);
	else if (choice[0] == 'r' && choice[1] == 'b')
		rotate(b);
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == '\0')
	{
		rotate(a);
		rotate(b);
	}
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'a')
		reverse(a);
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'b')
		reverse(b);
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'r')
	{
		reverse(a);
		reverse(b);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}
