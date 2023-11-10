/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:06 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/10 18:38:16 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int						value;
	int						current_position;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
	struct s_stack_node		*target_node;
}	t_stack;

// Handle input
char	**ft_split(char const *s, char c);

void	check_args(char **argv);
int	is_duplicate(int nb1, int nb2);

#endif