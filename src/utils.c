/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:28 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/30 18:55:09 by gcampos-         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	absolute_nb(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, &*c, 1);
		c++;
	}
}
