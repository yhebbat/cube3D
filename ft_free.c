#include "cub3d.h"
#include "get_next_line.h"

void		ft_free(char **p, int j)
{
	while (p[j])
	{
		free(p[j]);
		j--;
	}
	free(p);
}

void		ft_free2(char **p)
{
	int i = 0;


	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}