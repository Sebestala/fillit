/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:11:00 by cmasetti          #+#    #+#             */
/*   Updated: 2017/12/12 09:46:38 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (ft_iswspc(s[start]))
		start++;
	if (start == len + 1)
		return (ft_strdup(""));
	while (ft_iswspc(s[len]))
		len--;
	len = len - start + 1;
	return (ft_strsub(s, start, len));
}
