/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:08 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/07 16:44:18 by dilovancand      ###   ########.fr       */
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
static char	*ft_cmdmalloc(char *str)
{
	char	*tmp;
	int		a;

	a = ft_cmd_strlen(str);
	tmp = malloc(sizeof(char) * (a + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}

//supprime les quotes et les espaces dans la string pour faciliter le parsing
char	*ft_cmdisgood(char *str)
{
	char	*tmp;
	int		a;
	int		b;
	char	c;

	tmp = ft_cmdmalloc(str);
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
