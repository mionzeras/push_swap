/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:25:50 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:18 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	//t_stack	*b;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		exit_err(NULL, NULL);
	a = create_stack(ac, av);
	//b = NULL;
	while (a)
	{
		printf("Number %d has index %i\n", a->value, a->index);
		a = a->next;
	}
}
