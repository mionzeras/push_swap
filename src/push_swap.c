/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:25:50 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/30 19:35:46 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		exit_err(NULL, NULL);
	stack_a = create_stack(ac, av);
	if (is_sorted(stack_a) == 1)
	{
		printf("The stack is already sorted\n");
		exit (EXIT_SUCCESS);
	}
	stack_b = NULL;
	while (stack_a)
	{
		printf("Number %d has index %i\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	sorting_test(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
