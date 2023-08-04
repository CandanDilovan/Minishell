/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:21:55 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/04 22:48:04 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	issep(char str, char sep)
{
	if (str == sep)
		return (1);
	return (0);
}

void	cpy(char *tab, char *s, int letters, int d)
{
	int	a;

	a = 0;
	while (a < d)
	{
		tab[a] = s[a + letters];
		a++;
	}
	tab[a] = '\0';
}

int	ft_count_tab(char *s, char c, int a, int tab_nb)
{
	char	flag;

	while (s[a])
	{
		while (s[a] && s[a] == c)
			a++;
		if (s[a] == 34 || s[a] == 39)
		{
			flag = s[a];
			while (s[a] != flag)
				a++;
			tab_nb++;
		}
		else if (s[a] && s[a] != c)
		{
			tab_nb++;
			while (s[a] && s[a] != c)
				a++;
		}
	}
	return (tab_nb);
}
