/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:36:35 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/04 16:29:09 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//parcours la chaine de caractère, vérifie si toutes les quotes sont fermés
int	is_quote_close(char *str)
{
	int	a;
	int	flag_d;
	int	flag_s;

	a = 0;
	flag_d = 0;
	flag_s = 0;
	while (str[a])
	{
		if (str[a] == 39 && flag_s != 2 && flag_d == 0)
			flag_s++;
		if (str[a] == 34 && flag_d != 2 && flag_s == 0)
			flag_d++;
		if (flag_d == 2)
			flag_d = 0;
		if (flag_s == 2)
			flag_s = 0;
		a++;
	}
	if (flag_d != 0 || flag_s != 0)
		return (1);
	return (0);
}

//un strlen qui ignore les quotes fermés et les multiples espaces 
static int	ft_spe_strlen(char *str)
{
	char	c;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while ((str[a + b] < '!' || str[a + b] > '~') && str[a])
		a++;
	while (str[a + b++])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			c = str[a + b];
			a++;
			while (str[a + b] != c)
				b++;
			if (c == ' ')
			{
				b++;
				while (str[a + b] == c)
					a++;
			}
		}
	}
	return (b);
}

//malloc la chaine de caractère
static char	*ft_minimalloc(char *str)
{
	char	*tmp;
	int		a;

	a = ft_spe_strlen(str);
	tmp = malloc(sizeof(char) * (a + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}

//supprime les quotes et les espaces dans la string pour faciliter le parsing
char	*ft_strisgood(char *str)
{
	char	*tmp;
	int		a;
	int		b;
	char	c;

	tmp = ft_minimalloc(str);
	b = 0;
	a = 0;
	while ((str[a + b] < '!' || str[a + b] > '~') && str[a])
		a++;
	while (str[a + b++])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			c = str[a + b];
			a++;
			while (str[a + b++] != c)
				tmp[b] = str[a + b];
		}
		else
			tmp[b] = str[a + b];
	}
	return (tmp);
}
