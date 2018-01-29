/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:23:13 by cmasetti          #+#    #+#             */
/*   Updated: 2017/12/03 15:52:42 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	if (len == 0)
		return (b);
	d = (unsigned char *)b;
	while (len > 0)
	{
		*d = (unsigned char)c;
		d++;
		len--;
	}
	return (b);
}
