/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:52:35 by sgarcia           #+#    #+#             */
/*   Updated: 2018/01/24 18:47:05 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

int					figure(t_coord *pos)
{
	int	max_abs;
	int	max_ord;
	int	i;

	i = 0;
	while (i < pos->sharp)
	{
		max_abs = 0;
		max_ord = 0;
		max_abs = ft_max(ft_max(pos->abs[i + 1], pos->abs[i + 2]),
					pos->abs[i + 3]) + ft_max(0, -ft_min(ft_min(pos->abs[i + 1],
							pos->abs[i + 2]), pos->abs[i + 3]));
		max_ord = ft_max(ft_max(pos->ord[i + 1], pos->ord[i + 2]),
				pos->ord[i + 3]);
		if ((max_abs + max_ord) > 3 || (pos->abs[i + 1] == 0 &&
					pos->abs[i + 2] == 2 && pos->abs[i + 3] == 2) ||
				(pos->ord[i + 1] == 0 && pos->ord[i + 2] == 2 &&
				pos->ord[i + 3] == 2))
			return (0);
		i += 4;
	}
	return (1);
}

t_coord				*placing(t_coord *pos)
{
	int	num_sharp;
	int	i;
	int	copy_abs;
	int copy_ord;

	num_sharp = 0;
	i = 0;
	while (num_sharp <= pos->sharp)
	{
		if (i % 4 == 0)
		{
			i = 0;
			copy_abs = pos->abs[num_sharp];
			copy_ord = pos->ord[num_sharp];
		}
		pos->abs[num_sharp] -= copy_abs;
		pos->ord[num_sharp] -= copy_ord;
		num_sharp++;
		i++;
	}
	return (pos);
}

t_coord				*coordonate(char *str, t_coord *pos)
{
	int	chara;
	int	tetri;

	chara = 0;
	pos->sharp = 0;
	tetri = 1;
	while (str[chara])
	{
		if ((chara + 1 - tetri) / (20 * tetri) == 1)
			tetri++;
		if (str[chara] == '#')
		{
			pos->abs[pos->sharp] = (chara - 21 * (tetri - 1)) % 5;
			pos->ord[pos->sharp] = (chara - 21 * (tetri - 1)) / 5;
			pos->sharp++;
		}
		chara++;
	}
	pos = placing(pos);
	return (pos);
}

t_coord				*verif_tetri(char *str, t_coord *pos, int chara)
{
	while (str[chara])
	{
		if (chara / (21 * pos->t - 1) == 1)
		{
			if (pos->sharp != 4 * pos->t || str[21 * pos->t - 1] != '\n')
				return (NULL);
			pos->t++;
		}
		if (str[chara] == '#')
			pos->sharp++;
		if ((str[chara] != '.' && str[chara] != '#' && str[chara] != '\n')
				|| ((chara + 2 - pos->t) % 5 == 0 && str[chara] != '\n')
				|| (str[chara] == '\n' && (!((chara + 2 - pos->t) % 5 == 0) ||
						(21 * pos->t - 1 == chara))))
			return (NULL);
		chara++;
	}
	if (pos->sharp != 4 * pos->t || pos->t > 26 || chara < 20)
		return (NULL);
	if (chara != 21 * pos->t - 1)
		return (NULL);
	return (pos);
}

t_coord				*testriminos(char *str)
{
	int			chara;
	t_coord		*pos;

	chara = 0;
	pos = (t_coord*)malloc(sizeof(t_coord));
	pos->t = 1;
	pos->sharp = 0;
	pos = verif_tetri(str, pos, chara);
	if (pos == NULL)
		return (pos);
	if (!(pos->abs = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(pos->abs);
		return (NULL);
	}
	if (!(pos->ord = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(pos->ord);
		return (NULL);
	}
	pos = coordonate(str, pos);
	if (!(figure(pos)))
		return (NULL);
	return (pos);
}
