/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:06:40 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/22 11:28:17 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numbers(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '+' || num[0] == '-')
	{
		if (!num[i + 1])
			return (0);
		i++;
	}
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;	
	}
	return (1);
}

int	is_duplicated(char **argv)
{
	int	i;
	int	j;
	long temp;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		temp = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == temp)
			{
				printf("duplicated number\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	printf("No duplicate numbers\n");
	return (0);
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