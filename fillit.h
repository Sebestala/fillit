/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:52:46 by cmasetti          #+#    #+#             */
/*   Updated: 2018/01/24 17:07:15 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct		s_coord
{
	int	*abs;
	int	*ord;
	int	sharp;
	int	t;
}					t_coord;

typedef struct		s_tetris
{
	int		x;
	int		c1[2];
	int		c2[2];
	int		c3[2];
}					t_tetris;

int					figure(t_coord *pos);
t_coord				*placing(t_coord *pos);
t_coord				*coordonate(char *str, t_coord *pos);
t_coord				*verif_tetri(char *str, t_coord *pos, int chara);
t_coord				*testriminos(char *str);
char				*gridmaker(int side);
int					freespc(t_tetris *tab, char *str, int side);
void				fillstr(t_tetris *tab, char *str, int side, char c);
int					nb(t_tetris **tab);
t_tetris			**transform(t_coord *pos);
void				fillit_setup(t_tetris **tab, int side);
void				fillit(t_tetris **tab, char *str, int side, int i);
t_coord				*testest(char *str);

#endif
