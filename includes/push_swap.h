/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:06 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/15 16:39:20 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
}	t_stack;

// Check input
int	is_numbers(char *num);
int	is_duplicated(char **argv);
int	check_args(char **argv);

// Creating stack
t_stack	*newstack(int nb);
void	stack_add_last(t_stack **stack, t_stack *new);
t_stack	*create_stack(int argc, char **argv);

// Utils
int		ft_atoi(const char *str);
void	exit_err(t_stack **a, t_stack **b);
#endif