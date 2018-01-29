/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:53:03 by cmasetti          #+#    #+#             */
/*   Updated: 2018/01/24 17:18:55 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		str[600];
	t_coord		*pos;
	t_tetris	**tab;
	int			side;

	if (argc != 2)
	{
		write(1, "usage: fillit tetriminos_file\n", 30);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if ((side = read(fd, str, 599)) >= 546)
		return (0);
	str[side] = '\0';
	close(fd);
	if (!(pos = testest(str)))
		return (0);
	tab = transform(pos);
	side = 2;
	while (side * side < 4 * pos->t)
		side++;
	fillit_setup(tab, side);
	return (0);
}
