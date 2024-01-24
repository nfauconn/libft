[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/libft/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/libft/blob/master/README.fr.md)

# Projet: Libft

## Introduction
Libft est notre premier projet en tant qu'étudiant à 42. Le but est de créer notre propre bibliothèque C en recodant un ensemble de fonctions de la libc, ainsi que d'autres fonctions utilitaires.

## Enjeux et apprentissages

### Langage C
  - **Analyse et Réingénierie de Fonctions Standards de la libc:** Compréhension du fonctionnement interne et capacité à recoder des fonctions standards pour une maîtrise approfondie.
  - **Maîtrise Avancée des Pointeurs:** Utilisation des pointeurs pour une gestion précise de la mémoire et des structures de données.
  - **Gestion Expert de la Mémoire:** Techniques avancées de gestion de la mémoire, y compris allocation, libération, et optimisation de l'utilisation de la mémoire.

### Pratiques de Développement et Outils

- **Maîtrise de l'Automatisation de Compilation avec Makefile** : Utilisation de Makefile pour la création de règles de compilation automatisées, optimisant ainsi le processus de build.
  
- **Adhésion aux Standards de Codage et Rédaction Normative (norme de 42)** : Application rigoureuse de la norme de codage 42 pour assurer la lisibilité, la maintenabilité et la qualité du code, tout en facilitant la collaboration et l'évaluation par les pairs.

- **Développement de Compétences en Recherche et en Documentation Technique** : Cultivation d'une approche méthodique pour la recherche et la compréhension de documentation technique, renforçant ainsi l'autonomie dans la résolution de problèmes et l'apprentissage de nouvelles technologies.

- **Intégration Basique des Flux de Travail Git** : Maîtrise des commandes fondamentales telles que `git add`, `git commit`, `git push`, et `git pull` pour un contrôle efficace des versions.

## Contenu du Projet

### Recoder un ensemble de fonctions de la libc
1. **Sans aucune fonction externe**: isalpha
• isdigit • isalnum • isascii • isprint • strlen • memset • bzero • memcpy • memmove • strlcpy • strlcat • toupper • tolower • strchr • strrchr • strncmp • memchr • memcmp • strnstr • atoi
2. **En utilisant uniquement `malloc`**: calloc
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
### Coder des fonctions utilitaires
- `ft_substr`: Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de la chaîne ’s’.  Cette nouvelle chaîne commence à l’index ’start’ et a pour taille maximale ’len’.
- `ft_strtrim`: Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les caractères spécifiés dans ’set’ au début et à la fin de la chaîne de caractères.
- `ft_split`: Alloue (avec malloc(3)) et retourne un tableau de chaînes de caractères obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
- `ft_strjoin`: Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat de la concaténation de s1 et s2.
- `ft_itoa`: Alloue (avec malloc(3)) et retourne une chaîne de caractères représentant l’entier ’n’ reçu en argument. Les nombres négatifs doivent être gérés.
- `ft_strmapi`: Applique la fonction ’f’ à chaque caractère de la chaîne de caractères passée en argument pour créer une nouvelle chaîne de caractères résultant des applications successives de ’f’.
- `ft_striteri`: Applique la fonction ’f’ à chaque caractère de la chaîne de caractères transmise comme argument, et en passant son index comme premier argument.  Chaque caractère est transmis par adresse à ’f’ afin d’être modifié si nécessaire.
- `ft_putchar_fd`: Écrit le caractère ’c’ sur le descripteur de fichier donné.
- `ft_putstr_fd`: Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.
- `ft_putendl_fd`: Écrit La chaîne de caractères ’s’ sur le descripteur de fichier donné suivie d’un retour à la ligne.
- `ft_putnbr_fd`: Écrit l’entier ’n’ sur le descripteur de fichier donné.

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
 
### Partie Bonus: manipulation de listes
- `ft_lstnew`: Alloue (avec malloc(3)) et renvoie un nouvel élément. La variable membre ’content’ est initialisée à l’aide de la valeur du paramètre ’content’. La variable ’next’ est initialisée à NULL.
- `ft_lst_add_front`: Ajoute l’élément ’new’ au début de la liste.
- `ft_lst_add_back`: Ajoute l’élément ’new’ à la fin de la liste.
- `ft_lst_size`: Compte le nombre d’éléments de la liste.
- `ft_lst_last`: Renvoie le dernier élément de la liste.
- `ft_lst_delone`: Libère la mémoire de l’élément passé en argument en utilisant la fonction ’del’ puis avec free(3). La mémoire de ’next’ ne doit pas être free.
- `ft_lst_clear`: Supprime et libère la mémoire de l’élément passé en paramètre, et de tous les éléments qui suivent, à l’aide de ’del’ et de free(3) Enfin, le pointeur initial doit être mis à NULL.
- `ft_lst_iter`: Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu chaque élément.
- `ft_lst_map`: Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu de chaque élément. Crée une nouvelle liste résultant des applications successives de ’f’. La fonction ’del’ est là pour détruire le contenu d’un élément si nécessaire.

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
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
```

## Ressources et Documentation
- [Manuels de la libc](https://linux.die.net/man/)