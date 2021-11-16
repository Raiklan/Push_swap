/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:02:48 by saich             #+#    #+#             */
/*   Updated: 2021/11/16 18:58:18 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(const char *str, size_t i)
{
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	size_t	i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (whitespace(str, i) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}
