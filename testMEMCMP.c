#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	src[10] = "COUCOOOOU";
	char	src2[2] = "COUCOOOOUU";

	printf("   memcmp = %d\n", memcmp(src, src2, 11));
	printf("ft_memcmp = %d\n", ft_memcmp(src, src2, 11));

	printf("   memcmp = %d\n", memcmp(NULL, src2, 13));
	printf("ft_memcmp = %d\n", ft_memcmp(NULL, src2, 13));
	return (0);
}
