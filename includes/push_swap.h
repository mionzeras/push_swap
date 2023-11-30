/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:06 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:09 by gcampos-         ###   ########.fr       */
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

// check_input.c
int		is_numbers(char *num);
int		is_duplicated(char **argv);
int		check_args(char **argv);

// init_stack.c
void	stack_add_last(t_stack **stack, t_stack *new);
void	index_stack(t_stack **stack);
t_stack	*newstack(int nb);
t_stack	*create_stack(int argc, char **argv);

// stack_utils.c
int		is_min(t_stack *stack);
int		stack_len(t_stack *stack);

// utils.c
int		ft_atoi(const char *str);
void	exit_err(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
#endif