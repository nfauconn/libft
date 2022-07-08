#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("ft_atoi(%s) = %d", av[1], ft_atoi(av[1]));
		printf("atoi(%s) = %d", av[1], atoi(av[1]));
	}
}
