/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:19:34 by cmasetti          #+#    #+#             */
/*   Updated: 2018/01/26 13:43:30 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

int			freespc(t_tetris *tab, char *str, int side)
{
	if (str[tab->x] != '.')
		return (0);
	if (str[tab->x + tab->c1[0] + tab->c1[1] * (side + 1)] != '.')
		return (0);
	if (str[tab->x + tab->c2[0] + tab->c2[1] * (side + 1)] != '.')
		return (0);
	if (str[tab->x + tab->c3[0] + tab->c3[1] * (side + 1)] != '.')
		return (0);
	return (1);
}

void		fillstr(t_tetris *tab, char *str, int side, char c)
{
	str[tab->x] = c;
	str[tab->x + tab->c1[0] + tab->c1[1] * (side + 1)] = c;
	str[tab->x + tab->c2[0] + tab->c2[1] * (side + 1)] = c;
	str[tab->x + tab->c3[0] + tab->c3[1] * (side + 1)] = c;
}

int			nb(t_tetris **tab)
{
	int		n;

	n = 0;
	while (tab[n])
		n++;
	return (n);
}

void		fillit_setup(t_tetris **tab, int side)
{
	char	*str;
	int		i;

	i = 0;
	while (tab[i])
		tab[i++]->x = 0;
	str = gridmaker(side);
	fillit(tab, str, side, 0);
}

void		fillit(t_tetris **tab, char *str, int side, int i)
{
	while (i != 0 || str[tab[i]->x + 1])
	{
		while (!freespc(tab[i], str, side) && str[tab[i]->x + 1])
		{
			(tab[i]->x)++;
			if (!(str[tab[i]->x + 1]))
			{
				if (i == 0)
				{
					free(str);
					fillit_setup(tab, side + 1);
					return ;
				}
				fillstr(tab[i - 1], str, side, '.');
				(tab[(i--) - 1]->x)++;
			}
		}
		fillstr(tab[i], str, side, 'A' + i);
		if (i == (nb(tab) - 1))
		{
			write(1, str, ft_strlen(str));
			return ;
		}
		tab[(i++) + 1]->x = 0;
	}
}
