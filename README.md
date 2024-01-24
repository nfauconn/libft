# Project: Libft

## Goal
Create our own C library by recoding a set of functions from the libc, as well as other utility functions.

## Challenges and Learning

### C Language
  - **Analysis and Re-engineering of Standard libc Functions:** Understanding the internal workings and the ability to recode standard functions for in-depth mastery.
  - **Advanced Mastery of Pointers:** Using pointers for precise memory management and data structures.
  - **Expert Memory Management:** Advanced techniques for memory management, including allocation, release, and optimization of memory usage.

### Development Practices and Tools

- **Mastery of Compilation Automation with Makefile**: Using Makefile for creating automated compilation rules, thus optimizing the build process.
  
- **Adherence to Coding Standards and Normative Writing (42 norm)**: Rigorous application of the 42 coding standard to ensure readability, maintainability, and code quality, while facilitating collaboration and peer review.

- **Development of Skills in Research and Technical Documentation**: Cultivating a methodical approach to research and understanding of technical documentation, thus strengthening autonomy in problem-solving and learning new technologies.

- **Basic Integration of Git Workflow**: Mastery of fundamental commands such as `git add`, `git commit`, `git push`, and `git pull` for efficient version control.

## Project Content

### Recoding a set of libc functions
1. **Without any external function**: isalpha
• isdigit • isalnum • isascii • isprint • strlen • memset • bzero • memcpy • memmove • strlcpy • strlcat • toupper • tolower • strchr • strrchr • strncmp • memchr • memcmp • strnstr • atoi
2. **Using only `malloc`**: calloc
• strdup
```c
#include "libft.h"

int	ft_atoi(const char *s)
{
	int					sign;
	unsigned long long	nbr;

	nbr = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if (nbr > LLONG_MAX)
		return ((-1) * sign);
	return ((int)(nbr * sign));
}
```
### Coding Utility Functions
- `ft_substr`: Allocates (with malloc(3)) and returns a string from the string ’s’. This new string starts at index ’start’ and has a maximum size of ’len’.
- `ft_strtrim`: Allocates (with malloc(3)) and returns a copy of the string ’s1’, without the characters specified in ’set’ at the beginning and the end of the string.
- `ft_split`: Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
- `ft_strjoin`: Allocates (with malloc(3)) and returns a new string, resulting from the concatenation of s1 and s2.
- `ft_itoa`: Allocates (with malloc(3)) and returns a string representing the integer ’n’ received as an argument. Negative numbers must be handled.
- `ft_strmapi`: Applies the function ’f’ to each character of the string passed as an argument to create a new string resulting from successive applications of ’f’.
- `ft_striteri`: Applies the function ’f’ to each character of the string passed as an argument, and passing its index as the first argument. Each character is passed by address to ’f’ to be modified if necessary.
- `ft_putchar_fd`: Writes the character ’c’ on the given file descriptor.
- `ft_putstr_fd`: Writes the string ’s’ on the given file descriptor.
- `ft_putendl_fd`: Writes the string ’s’ on the given file descriptor followed by a newline.
- `ft_putnbr_fd`: Writes the integer ’n’ on the given file descriptor.

```c
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		new[j + i] = s2[i];
		i++;
	}
	new[j + i] = '\0';
	return (new);
}
```

```c
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
```
 
### Bonus Part: list manipulation
- `ft_lstnew`: Allocates (with malloc(3)) and returns a new element. The member variable ’content’ is initialized using the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
- `ft_lst_add_front`: Adds the element ’new’ at the beginning of the list.
- `ft_lst_add_back`: Adds the element ’new’ at the end of the list.
- `ft_lst_size`: Counts the number of elements in the list.
- `ft_lst_last`: Returns the last element of the list.
- `ft_lst_delone`: Frees the memory of the element passed as an argument using the function ’del’ then with free(3). The memory of ’next’ must not be freed.
- `ft_lst_clear`: Deletes and frees the memory of the element passed as a parameter, and all the elements that follow, using ’del’ and free(3). Finally, the initial pointer should be set to NULL.
- `ft_lst_iter`: Iterates over the list ’lst’ and applies the function ’f’ to the content of each element.
- `ft_lst_map`: Iterates over the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting from successive applications of ’f’. The function ’del’ is there to destroy the content of an element if necessary.

```c
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->

next)
		curr = curr->next;
	curr->next = new;
}
```

## Resources and Documentation
- [Libc Manuals](https://linux.die.net/man/)