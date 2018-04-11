/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:39:47 by sgarcia           #+#    #+#             */
/*   Updated: 2018/01/26 13:43:07 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

char		*gridmaker(int side)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(side * (side + 1));
	while (i < (side * (side + 1)))
	{
		if (!((i + 1) % (side + 1)))
			str[i++] = '\n';
		else
			str[i++] = '.';
	}
	return (str);
}

t_tetris	**transform(t_coord *pos)
{
	int			i;
	t_tetris	**tab;

	i = 0;
	tab = ft_memalloc(sizeof(t_tetris) * (pos->t + 1));
	while (i < pos->t)
	{
		tab[i] = ft_memalloc(sizeof(t_tetris));
		tab[i]->x = 0;
		(tab[i]->c1)[0] = pos->abs[i * 4 + 1];
		(tab[i]->c1)[1] = pos->ord[i * 4 + 1];
		(tab[i]->c2)[0] = pos->abs[i * 4 + 2];
		(tab[i]->c2)[1] = pos->ord[i * 4 + 2];
		(tab[i]->c3)[0] = pos->abs[i * 4 + 3];
		(tab[i]->c3)[1] = pos->ord[i * 4 + 3];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

t_coord		*testest(char *str)
{
	t_coord		*pos;

	if (!(pos = testriminos(str)))
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	return (pos);
}
