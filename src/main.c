/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:00:22 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/15 15:01:20 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int		size;
	
	if (argc < 2)
		return (0);
	if (!check_args(argv))
		exit_err(NULL, NULL);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	
	return (0);
}
