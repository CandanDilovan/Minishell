/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:29:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/04 23:56:17 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**free_all(char **tab, int a)
{
	while (0 <= a)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

static int	is_quote(char *tab, char *s, int letters)
{
	char	quote;
	int		d;

	d = 0;
	quote = s[letters];
	while (s[letters + d] != quote)
		d++;
	tab = malloc(sizeof(char) * (d + 1));
	if (!tab)
		return (-1);
	cpy(tab, s, letters, d);
	return (d + letters);
}

static int	no_quote(char *tab, char *s, char c, int letters)
{
	int	d;

	d = 0;
	while (issep(s[letters + d], c) == 0 && s[letters + d])
		d++;
	tab = malloc(sizeof(char) * (d + 1));
	if (tab == 0)
		return (-1);
	cpy(tab, (char *)s, letters, d);
	return (d + letters);
}

static char	**into_tab(char **tab, char const *s, char c)
{
	int	letters;
	int	b;

	b = 0;
	letters = 0;
	while (s[letters])
	{
		if (s[letters] == 34 || s[letters] == 39)
		{
			if (is_quote(tab[b], (char *)s, letters) == -1)
				return (free_all(tab, (b - 1)));
			letters = is_quote(tab[b++], (char *)s, letters);
		}
		else if (issep(s[letters], c) == 0)
		{
			if (no_quote(tab[b], (char *)s, c, letters) == -1)
				return (free_all(tab, (b - 1)));
			letters = no_quote(tab[b++], (char *)s, c, letters);
		}
		else
			letters++;
	}
	tab[b] = 0;
	return (tab);
}

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
	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (tab == 0)
		return (NULL);
	return (into_tab(tab, s, c));
}
