#include "cub3d.h"
#include "get_next_line.h"

void		ft_free(char **p, int j)
{
	while (p[j--])
		free(p[j]);
	free(p);
}