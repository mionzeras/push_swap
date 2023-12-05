/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:41:15 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/05 15:11:11 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (*choice == "sa")
		swap(sa);
	else if (*choice == "sb")
		swap(sb);
	else if (*choice == "ss")
	{
		swap(sa);
		swap(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}

void	rotate_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (*choice == "ra")
		rotate(sa);
	else if (*choice == "rb")
		rotate(sb);
	else if (*choice == "rr")
	{
		rotate(sa);
		rotate(sb);
	}
	else if (*choice == "rra")
		reverse(sa);
	else if (*choice == "rrb")
		reverse(sb);
	else if (*choice == "rrr")
	{
		reverse(sa);
		reverse(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}

void	push_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (*choice == "pa")
		push(sb, sa);
	else if (*choice == "pb")
		push(sa, sb);
	ft_putstr(choice);
	ft_putstr("\n");
}
