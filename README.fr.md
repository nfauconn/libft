[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/libft/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/libft/blob/master/README.fr.md)

*Langage de programmation C* • *Fonctions standard de la libc* • *Pointeurs* • *Opérations binaires* • *Conversions de type de bas niveau* • *Gestion de la mémoire* • *Gestion des erreurs* • *Normes de codage (Conformité aux normes)* • *Automatisation de la compilation avec Makefile* • *Flux de travail Git de base*

# Libft

Recodage d'un ensemble de fonctions de la libc, ainsi que d'autres fonctions utilitaires.

### Fonctions de la Libc

| Fonction externe | Fonction à implémenter |
|-|-|
**Sans aucune fonction externe** | `isalpha` `isdigit` `isalnum` `isascii` `isprint` `strlen` `memset` `bzero` `memcpy` `memmove` `strlcpy` `strlcat` `toupper` `tolower` `strchr` `strrchr` `strncmp` `memchr` `memcmp` `strnstr` `atoi`
**Utilisant uniquement `malloc`** | `calloc` `strdup`
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
### Fonctions utilitaires non-libc
| Fonction | Description |
|----------|-------------|
| `ft_substr` | Alloue (avec malloc(3)) et retourne une chaîne de caractères de la chaîne ’s’. Cette nouvelle chaîne commence à l'indice ’start’ et a une taille maximale de ’len’. |
| `ft_strtrim` | Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les caractères spécifiés dans ’set’ au début et à la fin de la chaîne. |
| `ft_split` | Alloue (avec malloc(3)) et retourne un tableau de chaînes obtenu en divisant ’s’ en utilisant le caractère ’c’ comme délimiteur. |
| `ft_strjoin` | Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultant de la concaténation de s1 et s2. |
| `ft_itoa` | Alloue (avec malloc(3)) et retourne une chaîne représentant l'entier ’n’ reçu en argument. Les nombres négatifs doivent être gérés. |
| `ft_strmapi` | Applique la fonction ’f’ à chaque caractère de la chaîne passée en argument pour créer une nouvelle chaîne résultant des applications successives de ’f’. |
| `ft_striteri` | Applique la fonction ’f’ à chaque caractère de la chaîne passée en argument, en passant son index comme premier argument. Chaque caractère est passé par adresse à ’f’ pour être modifié si nécessaire. |
| `ft_putchar_fd` | Écrit le caractère ’c’ sur le descripteur de fichier donné. |
| `ft_putstr_fd` | Écrit la chaîne ’s’ sur le descripteur de fichier donné. |
| `ft_putendl_fd` | Écrit la chaîne ’s’ sur le descripteur de fichier donné suivi d'un saut de ligne. |
| `ft_putnbr_fd` | Écrit l'entier ’n’ sur le descripteur de fichier donné. |
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
	new = malloc(sizeof(char) * (i + 1));
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

### Manipulation de listes
| Fonction | Description |
|----------|-------------|
| `ft_lstnew` | Alloue (avec malloc(3)) et retourne un nouvel élément. La variable membre ’content’ est initialisée en utilisant la valeur du paramètre ’content’. La variable ’next’ est initialisée à NULL. |
| `ft_lst_add_front` | Ajoute l'élément ’new’ au début de la liste. |
| `ft_lst_add_back` | Ajoute l'élément ’new’ à la fin de la liste. |
| `ft_lst_size` | Compte le nombre d'éléments dans la liste. |
| `ft_lst_last` | Retourne le dernier élément de la liste. |
| `ft_lst_delone` | Libère la mémoire de l'élément passé en argument en utilisant la fonction ’del’ passee en argument puis avec free(3). La mémoire de ’next’ ne doit pas être libérée. |
| `ft_lst_clear` | Supprime et libère la mémoire de l'élément passé en paramètre, et de tous les éléments qui suivent, en utilisant ’del’ et free(3). Finalement, le pointeur initial doit être mis à NULL. |
| `ft_lst_iter` | Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu de chaque élément. |
| `ft_lst_map` | Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu de chaque élément. Crée une nouvelle liste résultant des applications successives de ’f’. La fonction ’del’ est là pour détruire le contenu d'un élément si nécessaire. |

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
	while (curr-> next)
		curr = curr->next;
	curr->next = new;
}
```
