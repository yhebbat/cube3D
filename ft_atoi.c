#include "get_next_line.h"

int		ft_atoi(const char *str)
{
	size_t	result;
	int		signe;

	result = 0;
	signe = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result > 4294967295 && signe == 1)
			return (-1);
		if (signe == -1 && result > 4294967295)
			return (0);
	}
	return ((int)result * signe);
}