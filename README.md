# Projet: Libft

## Introduction
Libft est notre premier projet en tant qu'étudiant à 42. Le but est de créer notre propre bibliothèque C en recodant un ensemble de fonctions de la libc, ainsi que d'autres fonctions utilitaires.

## Objectifs
Ce projet nous permet de reprendre les bases de la programmation en C et de nous préparer pour les projets futurs.

## Enjeux
- Comprendre le fonctionnement interne de certaines fonctions standards de la libc.
- Apprendre à gérer la mémoire manuellement et de manière rigoureuse.
- S'habituer à la lecture de documentation et à l'utilisation des manuels.

## Contraintes Techniques
1. Le projet doit être écrit en C conformément à la Norme de l'école.
2. Aucune fuite de mémoire n'est évidemment tolérée.
3. Gestion d'erreurs rigoureuse.
4. Utilisation d'un Makefile pour compiler la bibliothèque.
5. Rendu et évaluation sur un dépôt Git.

## Contenu du Projet
Le projet se divise en plusieurs parties :

1. **Partie Obligatoire :** 
   - Recoder un ensemble de fonctions de la libc comme `atoi`, `memset`, `strlcat`, etc.
   - Coder des fonctions utilitaires comme:
     - `ft_split`: Alloue (avec malloc) et retourne un tableau de chaînes de caractères obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
	 - `ft_strjoin`: Alloue (avec malloc) et retourne une nouvelle chaîne, résultat de la concaténation de s1 et s2.  Le tableau doit être terminé par NULL.
	 - `ft_itoa`: Alloue (avec malloc) et retourne une chaîne de caractères représentant l’entier ’n’ reçu en argument. Les nombres négatifs doivent être gérés.
	 - `ft_strmapi`: Applique la fonction ’f’ à chaque caractère de la chaîne de caractères passée en argument pour créer une nouvelle chaîne de caractères (avec malloc) résultant des applications successives de ’f’.
   - La bibliothèque doit être compilée en libft.a et placée à la racine du dépôt Git.
   
2. **Partie Bonus :** 
   - Fonctions utilitaires de manipulation de listes (ajout / suppression / modification d'un elements de liste, iteration d'une fonction sur la liste, suppression de la liste)

## Apprentissages
- **Langage C:** Comprendre et utiliser des pointeurs, gérer la mémoire.
- **Makefile:** Écrire des Makefiles pour compiler le projet et gérer ses dépendances.
- **Gestion de projet:** Organiser son code, documenter son travail et respecter un cahier des charges.
- **Version Control (Git):** Utiliser Git pour le versionnage du code et pour le rendu du projet.

## Ressources et Documentation
- [Manuels de la libc](https://linux.die.net/man/)
