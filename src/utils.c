/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:28 by gcampos-          #+#    #+#             */
/*   Updated: 2024/04/09 15:38:34 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absol(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_numbers(char *num)
{
	int			i;
	long int	numb;

	i = 0;
	numb = ft_atoi(num);
	if (numb > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
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
	int		i;
	int		j;
	long	temp;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		temp = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == temp)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;

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
	return (sign * result);
}

void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, &*c, 1);
		c++;
	}
}
