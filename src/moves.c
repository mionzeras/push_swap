/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:41:15 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/06 11:17:58 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (choice[0] == 's' && choice[1] == 'a')
		swap(sa);
	else if (choice[0] == 's' && choice[1] == 'b')
		swap(sb);
	else if (choice[0] == 's' && choice[1] == 's')
	{
		swap(sa);
		swap(sb);
	}
	if (choice[0] == 'p' && choice[1] == 'a')
		push(sb, sa);
	else if (choice[0] == 'p' && choice[1] == 'b')
		push(sa, sb);
	ft_putstr(choice);
	ft_putstr("\n");
}

void	rotate_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (choice[0] == 'r' && choice[1] == 'a')
		rotate(sa);
	else if (choice[0] == 'r' && choice[1] == 'b')
		rotate(sb);
	else if (choice[0] == 'r' && choice[1] == 'r')
	{
		rotate(sa);
		rotate(sb);
	}
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'a')
		reverse(sa);
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'b')
		reverse(sb);
	else if (choice[0] == 'r' && choice[1] == 'r' && choice[2] == 'r')
	{
		reverse(sa);
		reverse(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}

/*void	push_move(t_stack **sa, t_stack **sb, char *choice)
{

	ft_putstr(choice);
	ft_putstr("\n");
}*/
