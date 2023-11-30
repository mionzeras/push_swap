/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:25:50 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/30 18:55:42 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_numbers(argv[i]))
		{
			printf("the arguent must be numbers\n");
			return (0);
		}
		i++;
	}
	if (is_duplicated(argv))
		return (0);
	return (1);
}

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
