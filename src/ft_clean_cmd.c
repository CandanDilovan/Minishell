/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:08 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/13 20:33:33 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//un strlen qui ignore les quotes fermés et les multiples espaces 
static int	ft_cmd_strlen(char *str)
{
	char	c;
	int		a;
	int		b;

	a = 0;
	b = -1;
	while ((str[a] < '!' || str[a] > '~') && str[a])
		a++;
	while (str[a + ++b])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			c = str[a + b];
			a++;
			while (str[a + b] != c && str[a + b])
				b++;
			if (c == ' ')
			{
				b++;
				while (str[a + b] == c && str[a + b])
					a++;
			}
		}
	}
	return (b);
}

//malloc la chaine de caractère
static char	*ft_cmdmalloc(char *str)
{
	char	*tmp;
	int		a;

	a = ft_cmd_strlen(str);
	tmp = malloc(sizeof(char) * (a));
	if (!tmp)
		return (NULL);
	return (tmp);
}

//Copie la chaine de charactère
static char	*ft_clean_copy(char *str, int a, char c)
{
	int		b;
	char	*tmp;

	tmp = ft_cmdmalloc(str);
	b = -1;
	while (str[a + ++b])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			if (!c)
				c = str[a + b];
			else
				c = 0;
			a++;
			while (str[a + b] != c && str[a + b])
			{
				tmp[b] = str[a + b];
				b++;
			}
		}
		else
			tmp[b] = str[a + b];
	}
	tmp[b] = '\0';
	return (tmp);
}

//supprime les quotes et les espaces dans la string pour faciliter le parsing
char	*ft_cmdisgood(char *str)
{
	char	*tmp;
	int		a;
	char	c;

	a = 0;
	c = 0;
	if (ft_isquote(str) == 1)
	{
		while ((str[a] < '!' || str[a] > '~') && str[a])
			a++;
		tmp = ft_clean_copy(str, a, c);
		return (tmp);
	}
	else
		return (str);
}
