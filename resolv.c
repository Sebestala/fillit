#include "fillit.h"

t_coord		*placement(char *str)
{
	int		a;
	int		s_square;
	t_coord	*pos;
	t_coord	*sq;

	a = 0;
	s_square = 2;
	pos = testriminos(str);
	if (pos == NULL)
	{
		write(1, "error", 5);
		return (NULL);
	}
	while (pos->sharp >= s_square * s_square)
		s_square++;
	if (!(sq->abs = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(sq->abs);
		return (NULL);
	}
	if (!(sq->ord = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(sq->ord);
		return (NULL);
	}
	ft_bzero(sq->abs, (size_t)pos->sharp + 1);
	ft_bzero(sq->ord, (size_t)pos->sharp + 1);
	sq->sharp = 0;
	sq->t = 1;


}


t_coord		*pos_is_valid(int a, t_coord *pos, t_coord *sq, int s_square)
{
	int		i;
	int		j;
	t_coord *copy_tmp;

	i = 0;
	if (!(copy_tmp->abs = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(copy_tmp->abs);
		return (NULL);
	}
	if (!(copy_tmp->ord = (int *)malloc((pos->sharp + 1) * sizeof(int))))
	{
		free(copy_tmp->ord);
		return (NULL);
	}
	while (i <= pos->sharp)
	{
		copy_tmp->abs[i] = sq->abs[i];
		copy_tmp->ord[i] = sq->ord[i];
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		if ((pos->abs[(sq->t - 1) * 4 + j] + a % (s_square - 1)) > s_square - 1 ||
				((pos->ord[(sq->t - 1) * 4 + j] + a / (s_square - 1)) > s_square - 1))
			return (NULL);
		while (j <= a)
		{
			if (((pos->abs[(sq->t - 1) * 4 + j] + a % (s_square - 1)) == sq->abs[j]) && 
					((pos->ord[(sq->t - 1) * 4 + j] + a / (s_square - 1)) == sq->ord[j]))
				return (NULL);
			j++;
		}
		copy_tmp->abs[(sq->t - 1) * 4 + i] = pos->abs[(sq->t - 1) * 4 + j] + a % (s_square - 1);
		copy_tmp->ord[(sq->t - 1) * 4 + i] = pos->ord[(sq->t - 1) * 4 + j] + a / (s_square - 1);
		i++;
	}
	copy_tmp->t++;
	return (copy_tmp);
}




t_coord		*recucu(int a, t_coord *pos, t_coord *sq, int s_square)
{
	t_coord		*tmp;

	tmp = pos_is_valid(a, pos, sq, s_square);
	if (tmp == NULL)
		recucu(a++, pos, sq, s_square);
	sq = tmp;

	*si la piece ne peut etre pose, que ord max est depasse, alors on remet a zero "a" et on incremente s_square, mais ce n'est pass une erreur! la boucle continuee !

}





t_coord		*recucu(int a, int o, t_coord *pos, t_coord *sq, int s_square)
{
	int		j;

	j = 0;
	while(j < 4)
	{
		if ((pos->abs[(sq->t - 1) * 4 + j]) >= s_square - 1)
			return recucu(0, o++, pos, sq, s_square);
		if ((pos->ord[(sq->t - 1) * 4 + j]) >= s_square - 1)
			return recucu(0, 0, pos, sq, s_square++);
		sq->abs[(sq->t - 1) * 4 + j] = pos->abs[(sq->t - 1) * 4 + j] + a;
		sq->ord[(sq->t - 1) * 4 + j] = pos->ord[(sq->t - 1) * 4 + j] + o;
	}

}
