/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:21:55 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/07 16:38:49 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//verifie si le char est un séparateur
int	issep(char str, char sep)
{
	if (str == sep)
		return (1);
	return (0);
}

/*
	copie la chaine de caractère en partant du int 'letters', 
	le int 'd' represente la taille totale de la chaine de caractère
*/
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

/*
	compte le nombre de case à allouer dans le tableau
	ignore tout ce qui se trouve entre single ou double quote
*/
int	ft_count_tab(char *s, char c, int a, int tab_nb)
{
	char	flag;

	while (s[a])
	{
		while (s[a] && s[a] == c)
			a++;
		if (s[a] && s[a] != c)
		{
			tab_nb++;
			while (s[a] && s[a] != c)
			{
				if (s[a] == 34 || s[a] == 39)
				{
					flag = s[a];
					a++;
					while (s[a] != flag)
						a++;
					a++;
				}
				else
					a++;
			}
		}
	}
	return (tab_nb);
}
