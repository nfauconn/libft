#include "libft.h"
#include <stdio.h>

int	main()
{
	int	i;

	i = 0;
	char **tab = ft_split("  tripouille  42  ", ' ');
 //	check(!strcmp(tab[1], "42"));
	while (tab[i])
	{
		printf("|%s|\n", tab[i]);
		i++;
	}
	return (0);
}