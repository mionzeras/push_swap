/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:06 by gcampos-          #+#    #+#             */
/*   Updated: 2023/12/29 09:38:30 by gcampos-         ###   ########.fr       */
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
	int						position;
	int						to_top_a;
	int						to_top_b;
	int						where_put_a;
	struct s_stack_node		*next;
}	t_stack;

// init_stack.c
void	index_stack(t_stack **stack);
void	stack_add_last(t_stack **stack, t_stack *new);
t_stack	*newstack(int nb);
t_stack	*create_stack(int argc, char **argv);

// move_functions.c
void	push(t_stack **from, t_stack **to);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);

// moves.c
void	swap_move(t_stack **a, t_stack **b, char *choice);
void	rotate_move(t_stack **a, t_stack **b, char *choice);


// push_swap.c
int		is_sorted(t_stack *stack);
int		check_args(char **argv);
void	push_swap(t_stack **a, t_stack **b);

// sorting_moves.c
int		target_a(t_stack **a, int b_index, int max, int a_pos);
void	stack_position(t_stack **stack);
void	closest_a(t_stack **a, t_stack **b);
void	calculate_to_top(t_stack **a, t_stack **b);

// sorting.c
void	small_sort(t_stack **stack);
void	push_until3(t_stack **a, t_stack **b);
void	complex_sort(t_stack **a, t_stack **b);

// stack_utils.c
void	exit_err(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
int		is_min(t_stack *stack);
int		max_index(t_stack *stack);
int		stack_len(t_stack *stack);

// utils.c
int		is_numbers(char *num);
int		is_duplicated(char **argv);
int		ft_atoi(const char *str);
void	ft_putstr(char *c);

#endif