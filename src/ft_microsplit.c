/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_microsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:28:59 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/11 14:16:09 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// /*
// 	compte le nombre de case à allouer dans le tableau
// 	ignore tout ce qui se trouve entre single ou double quote
// */
// static int	ft_count_tab(char *s, char c, int a, int tab_nb)
// {
// 	char	flag;

// 	while (s[a])
// 	{
// 		while (s[a] && s[a] == c)
// 			a++;
// 		if (s[a] && s[a] != c)
// 		{
// 			tab_nb++;
// 			while (s[a] && s[a] != c)
// 			{
// 				if (s[a] == 34 || s[a] == 39)
// 				{
// 					flag = s[a];
// 					a++;
// 					while (s[a] != flag)
// 						a++;
// 					a++;
// 				}
// 				else
// 					a++;
// 			}
// 		}
// 	}
// 	return (tab_nb);
// }

// //free tout le tableau de chaine de caractère
// static char	**free_all(char **tab, int a)
// {
// 	while (0 <= a)
// 	{
// 		free(tab[a]);
// 		a--;
// 	}
// 	free(tab);
// 	return (NULL);
// }

// //malloc et remplie la chaine de caractère 
// static int	no_quote(char **tab, char c, char *s, int letters)
// {
// 	int		d;
// 	char	quote;

// 	d = 0;
// 	while (issep(s[letters + d], c) == 0 && s[letters + d])
// 	{
// 		if (s[letters + d] == 34 || s[letters + d] == 39)
// 		{
// 			quote = s[letters + d];
// 			d++;
// 			while (s[letters + d] != quote)
// 				d++;
// 			d++;
// 		}
// 		else
// 			d++;
// 	}
// 	*tab = malloc(sizeof(char) * (d + 1));
// 	if (*tab == 0)
// 		return (-1);
// 	cpy(*tab, (char *)s, letters, d);
// 	return (d);
// }

// /*
// 	remplie le tableau de chaine de caractère avant de le renvoyer
// */
// static char	**into_tab(char **tab, char const *s)
// {
// 	int	letters;
// 	int	b;
// 	int	d;

// 	b = 0;
// 	letters = 0;
// 	while (s[letters])
// 	{
// 		if (issep(s[letters]) == 0)
// 		{
// 			d = no_quote(&tab[b++], (char *)s, letters);
// 			if (d == -1)
// 				return (free_all(tab, (b - 1)));
// 			letters = letters + d;
// 		}
// 		else
// 			letters++;
// 	}
// 	tab[b] = 0;
// 	return (tab);
// }

//un split qui ignore les espaces à l'intérieur d'une single ou double quote
char	**ft_microsplit(char const *s)
{
	int		tab_nb;
	int		real_tab;
	char	**tab;
	int		a;

	tab_nb = 0;
	real_tab = 0;
	a = 0;
	if (!s)
		return (NULL);
	real_tab = ft_count_tab((char *)s, ' ', a, tab_nb);
	ft_printf("%d\n", real_tab);
	real_tab = ft_count_tab((char *)s, '\t', a, tab_nb) + (real_tab - 1);
	ft_printf("%d\n", real_tab);
	real_tab = ft_count_tab((char *)s, '<', a, tab_nb) + (real_tab - 1);
	ft_printf("%d\n", real_tab);
	real_tab = ft_count_tab((char *)s, '>', a, tab_nb) + (real_tab - 1);
	ft_printf("%d\n", real_tab);
	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (tab == 0)
		return (NULL);
	//return (into_tab(tab, s));
	return (0);
}
