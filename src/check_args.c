/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:06:40 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/10 18:38:27 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int nb1, int nb2)
{
	if (nb1 == nb2)
			return (1);
	return (0);
}

void	check_args(char **argv)
{

}

int main(int ac, char **av)
{
	if (ac == 2)
		check_args(av);
	return (0);
}