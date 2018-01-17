#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct		s_coord
{
	int	*abs;	// tableau coordonnees abscisses
	int	*ord;	// tableau coordonnees ordonnees
	int	sharp;	// nb de '#'
	int	t;		// nb de tetriminos
}					t_coord;

t_coord				*testriminos(char *str);
t_coord				*placement(char *str);

#endif
