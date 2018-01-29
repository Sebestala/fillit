/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:44:09 by cmasetti          #+#    #+#             */
/*   Updated: 2017/12/12 10:45:38 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long long int	result;

	i = 0;
	neg = 0;
	result = 0;
	while (ft_iswspc(str[i]))
		i++;
	if (str[i] == '-')
		neg++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= 922337203685477580 && str[i] > '7' && neg == 0)
			return (-1);
		if (result >= 922337203685477580 && str[i] > '8' && neg == 1)
			return (0);
		result = 10 * result + str[i++] - 48;
	}
	return (neg ? ((int)-result) : ((int)result));
}
