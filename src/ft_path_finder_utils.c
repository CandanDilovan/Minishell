/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:14:56 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/31 20:29:13 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//un strlen qui renvoie la taille restante de la string
int	ft_path_strlen(char *str, int b)
{
	size_t	a;

	a = 0;
	while (str[a + b])
	{
		a++;
	}
	return (a);
}
