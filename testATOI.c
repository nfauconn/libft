#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_atoi(%s) = %d\n", NULL, ft_atoi(NULL));
		printf("   atoi(%s) = %d\n", NULL, atoi(NULL));
	}
	return (0);
}
