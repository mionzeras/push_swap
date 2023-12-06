/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:25:50 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/06 11:24:47 by gcampos-         ###   ########.fr       */
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

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;
	int	i;
	int pushed;

	i = 0;
	pushed = 0;
	len = stack_len(*a);
	while (i < len)
	{
		if ((*a)->index >= len / 2)
			{
				swap_move(a, b, "pb");
				pushed++;
			}
		else
			rotate_move(a, NULL, "ra");
		i++;
	}
	while (pushed--)
	{
		swap_move(a, b, "pa");
	}
	while (*a)
	{
		printf("a: %d\n", (*a)->value);
		(*a) = (*a)->next;
	}
	free_stack(a);
	free_stack(b);
	exit(0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

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
	tmp = stack_a;
	while (tmp)
	{
		printf("Number %d has index %i\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	push_swap(&stack_a, &stack_b);
	//sorting_test(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
