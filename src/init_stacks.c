/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:25:01 by gcampos-          #+#    #+#             */
/*   Updated: 2024/01/03 15:52:39 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	int		index;

	index = 1;
	temp = *stack;
	while (temp)
	{
		if (temp->index == -1)
		{
			min = is_min(temp);
			if (temp->value == min && temp->index == -1)
			{
				temp->index = index;
				index++;
				temp = *stack;
			}
			else
				temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

t_stack	*newstack(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nb;
	new->index = -1;
	new->position = -1;
	new->to_top_a = -1;
	new->to_top_b = -1;
	new->where_put_a = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_last(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack		*sa;
	long int	nb;
	int			i;

	sa = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_err(&sa, NULL);
		if (i == 1)
			sa = newstack((int)nb);
		else
			stack_add_last(&sa, newstack((int)nb));
		i++;
	}
	index_stack(&sa);
	return (sa);
}
