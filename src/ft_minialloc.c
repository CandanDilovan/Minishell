/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minialloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:23:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/10 22:40:36 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_core	*ft_alloc_core(char **tab, int a)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->str = tab[a];
	if (a == 0)
		core->type = CMD;
	else if (find_char(tab[a], '-') == 1)
		core->type = FLAG;
	else
		core->type = ARG;
	return (core);
}

void	ft_alloc_mantle(char **tab, t_mantle *mantle)
{
	t_core	*tmp;
	t_list	*list_tmp;
	int		a;

	a = -1;
	while (tab[++a])
	{
		tmp = ft_alloc_core(tab, a);
		list_tmp = ft_lstnew(tmp);
		ft_lstadd_back(&mantle->first, list_tmp);
	}
}

static t_crust	*ft_alloc_crust(char **tab, int a)
{
	t_crust	*crust;

	crust = malloc(sizeof(t_crust));
	if (!crust)
		return (NULL);
	crust->input = tab[a];
	return (crust);
}

void	ft_alloc_space(char **tab, t_list **space)
{
	t_crust	*tmp;
	t_list	*list_tmp;
	int		a;

	a = -1;
	while (tab[++a])
	{
		tmp = ft_alloc_crust(tab, a);
		list_tmp = ft_lstnew((void *)tmp);
		ft_lstadd_back(space, list_tmp);
	}
}
