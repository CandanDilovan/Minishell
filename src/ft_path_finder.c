/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:09:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/31 20:30:51 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//calcul la taille du $path pour le malloc par la suite
static int	ft_path_size(char *str)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a] && str[a] != '$')
		a++;
	if (str[a] == '$')
	{
		while (str[a + b] >= '!' && str[a + b] <= '~' && str[a + b])
		{
			b++;
			if (str[a + b] == '$')
				return (b);
		}
		return (b);
	}
	return (0);
}

//copie le $path pour getenv
static char	*ft_preprint(char *str, int b, int a)
{
	char	*tmp;
	int		c;

	c = 1;
	tmp = malloc(sizeof(char) * (b));
	if (!tmp)
		return (NULL);
	while (c < b)
	{
		tmp[c - 1] = str[a + c];
		c++;
	}
	tmp[c] = '\0';
	return (tmp);
}

//sépare la chaine de caractère en deux
static void	ft_split_path(char *str, t_pathport **pathing, int a)
{
	int	b;
	int	c;

	b = a + (ft_path_size(str));
	c = 0;
	(*pathing)->string1 = malloc(sizeof(char) * (a + 1));
	if (!(*pathing)->string1)
		return ;
	while (c < a)
	{
		(*pathing)->string1[c] = str[c];
		c++;
	}
	c = ft_path_strlen(str, b);
	(*pathing)->string2 = malloc(sizeof(char) * (c + 1));
	if (!(*pathing)->string2)
		return ;
	c = 0;
	while (str[b + c])
	{
		(*pathing)->string2[c] = str[b + c];
		c++;
	}
}

/* 
	coupe la chaine de caractère en deux isole le $PATH puis 
	recolle la chaine en ajoutant le chemin d'accès à la place
	$PATH
*/
char	*ft_print_path(char *str)
{
	int			a;
	int			b;
	t_pathport	*pathing;

	a = 0;
	pathing = malloc(sizeof(t_pathport));
	if (!pathing)
		return (NULL);
	pathing->final = str;
	while (pathing->final[a])
	{
		if (pathing->final[a] == '$')
		{
			b = ft_path_size(pathing->final);
			pathing->pathifik = ft_preprint(pathing->final, b, a);
			pathing->pathion = getenv(pathing->pathifik);
			ft_split_path(pathing->final, &pathing, a);
			pathing->final = ft_strjoin(pathing->string1, pathing->pathion);
			pathing->final = ft_strjoin(pathing->final, pathing->string2);
			free(pathing->string1);
			free(pathing->string2);
		}
		a++;
	}
	return (pathing->final);
}
