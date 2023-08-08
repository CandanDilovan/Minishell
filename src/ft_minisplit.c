/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:29:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/07 16:40:18 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//free tout le tableau de chaine de caractère
char	**free_all(char **tab, int a)
{
	while (0 <= a)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

//malloc et remplie la chaine de caractère 
static int	no_quote(char **tab, char *s, char c, int letters)
{
	int		d;
	char	quote;

	d = 0;
	while (issep(s[letters + d], c) == 0 && s[letters + d])
	{
		if (s[letters + d] == 34 || s[letters + d] == 39)
		{
			quote = s[letters + d];
			d++;
			while (s[letters + d] != quote)
				d++;
			d++;
		}
		else
			d++;
	}
	*tab = malloc(sizeof(char) * (d + 1));
	if (*tab == 0)
		return (-1);
	cpy(*tab, (char *)s, letters, d);
	return (d);
}

/*
	remplie le tableau de chaine de caractère avant de le renvoyer
*/
static char	**into_tab(char **tab, char const *s, char c)
{
	int	letters;
	int	b;
	int	d;

	b = 0;
	letters = 0;
	while (s[letters])
	{
		if (issep(s[letters], c) == 0)
		{
			d = no_quote(&tab[b++], (char *)s, c, letters);
			if (d == -1)
				return (free_all(tab, (b - 1)));
			letters = letters + d;
		}
		else
			letters++;
	}
	tab[b] = 0;
	return (tab);
}

//un split qui ignore les espaces à l'intérieur d'une single ou double quote
char	**ft_minisplit(char const *s, char c)
{
	int		tab_nb;
	char	**tab;
	int		a;

	tab_nb = 0;
	a = 0;
	if (!s)
		return (NULL);
	tab_nb = ft_count_tab((char *)s, c, a, tab_nb);
	ft_printf("%d\n", tab_nb);
	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (tab == 0)
		return (NULL);
	return (into_tab(tab, s, c));
}
