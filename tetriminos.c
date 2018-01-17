#include "fillit.h"

int					figure(t_coord *pos)// fonction pour verifier si le tetriminos a une forme valide, avec 4 '#' qui se touchent
{
	int	max_abs;
	int	max_ord;
	int	i;

	i = 0;
	max_abs = 0;
	max_ord = 0;
	while (i <= pos->sharp)
	{
		if (i % 4 == 0)
		{
			if (max_abs + max_ord > 3)// si la forme n'est pas valide il y aura plus de 3
				return (0);
			max_abs = 0;
			max_ord = 0;
		}
		if (pos->abs[i] < 0)
			pos->abs[i] *= -1;
		if (pos->ord[i] < 0)
			pos->ord[i] *= -1;
		if (pos->abs[i] > max_abs)
			max_abs = pos->abs[i];
		if (pos->ord[i] > max_ord)
			max_ord = pos->ord[i];
		i++;
	}
	return (1);
}

t_coord				*placing(t_coord *pos)// fonction pour placer les tetriminos en haut a gauche dans leurs grilles respective
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

t_coord				*coordonate(char *str, t_coord *pos) //fonction pour noter les coordonnees des tetriminos dans leurs grilles respectives dans deux tableaux
{
	int	chara;
	int	tetri;	// Num du '#'

	chara = 0;
	pos->sharp = 0;
	tetri = 1;
	while (str[chara])
	{
		if ((chara + 1 - tetri) / (20 * tetri) == 1) // condition qui se verifie qd on est sur la ligne entre chaques tetri
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
	pos->t = 1;
	while (str[chara])
	{
		if ((chara + 1 - pos->t) / (20 * pos->t) == 1) // condition qui se verifie qd on est sur la ligne entre chaques tetri
		{
			if (pos->sharp != 4 * pos->t || str[21 * pos->t - 1] != '\n')
				return (NULL);
			pos->t++;
		}
		if (str[chara] == '#')
			pos->sharp++;
		if ((str[chara] != '.' && str[chara] != '#' && str[chara] != '\n')
				|| ((chara + 2 - pos->t) % 5 == 0 && str[chara] != '\n') // si il y a  '\n' apres chaques 4 x '.'
				|| (str[chara] == '\n' && (!((chara + 2 - pos->t) % 5 == 0) ||
						(21 * pos->t - 1 == chara)))) // si il y a un '\n' de trop
			return (NULL);
		chara++;
	}
	if (pos->sharp != 4 * pos->t || pos->t > 26 || chara < 20)
		return (NULL);
	if (chara != 21 * pos->t - 1) // verifier le bon nombre de chara
		return (NULL);
	return (pos);
}

t_coord				*testriminos(char *str)
{
	int			chara;// nb de caracteres
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
