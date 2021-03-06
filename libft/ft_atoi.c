/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:00:22 by clora-ro          #+#    #+#             */
/*   Updated: 2021/11/22 17:19:21 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	boucle(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	space(char c)
{
	return (boucle(c, "\t\n\v\f\r "));
}

static int	operator(char c)
{
	return (boucle(c, "+-"));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	signe;
	int	j;

	result = 0;
	j = 0;
	signe = 1;
	while (space(*str))
		str++;
	while (operator(*str))
	{
		j++;
		if (j > 1)
			return (0);
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * signe);
}
