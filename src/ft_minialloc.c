/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minialloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:23:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/23 11:11:46 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//malloc et remplie chaque core en définissant son type
static t_core	*ft_alloc_core(char **tab, int a)
{
	t_core		*core;
	t_pathport	*path;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->str = tab[a];
	if (ft_ispth(core->str) == 1)
	{	
		path = malloc(sizeof(t_pathport));
		if (!path)
			return (NULL);
		core->str = ft_print_path(core->str, path);
	}
	if (!core->str)
		return (core);
	if (a == 0)
		core->type = CMD;
	else if (find_char(tab[a], '-') == 1)
		core->type = FLAG;
	else
		core->type = ARG;
	return (core);
}

//créer une liste chainée de core dans mantle
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

//maloc et remplie chaque crust avec leurs input à gérer 
static t_crust	*ft_alloc_crust(char **tab, int pipe, int a)
{
	t_crust	*crust;

	crust = malloc(sizeof(t_crust));
	if (!crust)
		return (NULL);
	crust->input = tab[a];
	ft_printf("%d\n", pipe);
	crust->pipe = pipe;
	return (crust);
}

//créer une liste chainée de crust
void	ft_alloc_space(char **tab, t_space **space)
{
	t_crust	*tmp;
	t_list	*list_tmp;
	int		a;

	a = -1;
	while (tab[++a])
	{
		tmp = ft_alloc_crust(tab, (*space)->tab[a], a);
		list_tmp = ft_lstnew((void *)tmp);
		ft_lstadd_back(&(*space)->crust, list_tmp);
	}
}
