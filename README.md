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

- Recoder un ensemble de fonctions de la libc comme `atoi`, `memset`, `strlcat`.
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
- Coder des fonctions utilitaires comme:
     - `ft_split`: Alloue et retourne un tableau de chaînes de caractères obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
	 - `ft_strjoin`: Alloue et retourne une nouvelle chaîne, résultat de la concaténation de s1 et s2.
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
	 - `ft_itoa`: Alloue et retourne une chaîne de caractères représentant l’entier ’n’ reçu en argument. Les nombres négatifs doivent être gérés.
	```c
	#include "libft.h"

	static int	find_len(long n)
	{
		int	i;

		i = 0;
		if (n == 0)
			return (1);
		if (n < 0)
		{
			n = -n;
			i++;
		}
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}

	char	*ft_itoa(int n)
	{
		char	*s;
		int		len;
		long	nb;

		nb = (long)n;
		len = find_len(nb);
		s = (char *)malloc(sizeof(char) * (len + 1));
		if (!s)
			return (NULL);
		s[len--] = '\0';
		if (nb == 0)
			s[len] = '0';
		if (nb < 0)
		{
			s[0] = '-';
			nb = -nb;
		}
		while (nb > 0)
		{
			s[len--] = nb % 10 + '0';
			nb = nb / 10;
		}
		return (s);
	}
	```
	 - `ft_strmapi`: Applique la fonction ’f’ à chaque caractère de la chaîne de caractères passée en argument pour créer une nouvelle chaîne de caractères résultant des applications successives de ’f’.
   - La bibliothèque doit être compilée en libft.a et placée à la racine du dépôt Git.
   
2. **Partie Bonus :** 
   - Fonctions utilitaires de manipulation de listes (ajout / suppression / modification d'un elements de liste, iteration d'une fonction sur la liste, suppression de la liste)

## Ressources et Documentation
- [Manuels de la libc](https://linux.die.net/man/)
