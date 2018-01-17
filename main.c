#include "fillit.h"

int					main(int argv, char **argc)
{
	int		fd;
	char	str[63001];

	if (argv == 2)
	{
		fd = open(argc[1], O_RDONLY);
		read(fd, str, 63000);
		if (!(testriminos(str)))
		{
			printf("ERROR");
			return(0);
		}
		else
			printf("valid");
	}
	else
			write(1, "\n", 1);
	return (0);
}
