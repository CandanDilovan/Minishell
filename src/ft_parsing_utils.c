/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:36:35 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/01 16:55:56 by dilovancand      ###   ########.fr       */
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

