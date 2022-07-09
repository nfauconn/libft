#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char src[100] = "COUCOOOOU";

	ft_memmove(src+5, src, strlen(src)+1);
	printf("ft_memmove = %s\n", src);

	char src1[100] = "COUCOOOOU";

	memmove(src1+5, src1, strlen(src1)+1);
	printf("   memmove = %s\n", src1);
	return (0);

	ft_memmove(NULL, NULL, 3);
	printf("ft_memmove = %s\n", src);

	memmove(NULL, NULL, 3);
	printf("   memmove = %s\n", src1);
	return (0);
}
