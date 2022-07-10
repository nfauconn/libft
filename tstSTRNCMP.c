#include "libft.h"
#include <string.h>


int main()
{
	printf("%d\n", strncmp("lol", "lol", -18));
	printf("%d\n", ft_strncmp("lol", "lol", -18));
}
