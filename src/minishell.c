/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/13 20:36:07 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	récupère la liste chainée contenant les cores les parcours
	retire les quotes qui ne sont pas dans d'autres quotes
	dans la chaine de charactère
*/
static void	remove_quotes(t_mantle *mantle)
{
	t_core	*core;
	char	*str;

	while (mantle->first)
	{
		core = (t_core *)mantle->first->content;
		str = ft_cmdisgood(core->str);
		ft_printf("%s\n", str);
		core->str = str;
		mantle->first = mantle->first->next;
	}
}

//gère l'input si il n'y a pas de pipe
static void	no_pipe(const char *str)
{
	t_crust		*crust;
	t_pathport	*path;
	char		**tab;

	crust = malloc(sizeof(t_crust));
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust || !crust->lst_cmd)
		return ;
	crust->input = (char *)str;
	if (ft_ispth(crust->input) == 1)
	{	
		path = malloc(sizeof(t_pathport));
		if (!path)
			return ;
		crust->input = ft_print_path(crust->input, path);
	}
	tab = ft_minisplit(crust->input, ' ');
	ft_alloc_mantle(tab, crust->lst_cmd);
	remove_quotes(crust->lst_cmd);
	print_core(crust->lst_cmd);
}

//remplie la liste chainée de crust (et les print pour le moment)
static void	ft_space2crust(t_list *list)
{
	t_crust		*crust;
	char		**tab;	
	t_pathport	*path;

	crust = (t_crust *)list->content;
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust->lst_cmd)
		return ;
	if (ft_ispth(crust->input) == 1)
	{
		path = malloc(sizeof(t_pathport));
		if (!path)
			return ;
		crust->input = ft_print_path(crust->input, path);
	}
	tab = ft_minisplit(crust->input, ' ');
	ft_alloc_mantle(tab, crust->lst_cmd);
	remove_quotes(crust->lst_cmd);
	print_core(crust->lst_cmd);
}

//coupe la string en plusieurs string par pipe
static void	is_pipe(const char *str)
{
	char	**output;
	t_space	*space;
	t_list	*test;

	space = malloc(sizeof(t_space));
	if (!space)
		return ;
	output = ft_minisplit(str, '|');
	ft_alloc_space(output, &space->crust);
	test = space->crust;
	while (test)
	{
		ft_space2crust(test);
		test = test->next;
	}
}

//boucle infini, affiche le prompt et gère les arguments envoyer
void	ft_minishell(void)
{
	char	*str;

	while (1)
	{
		str = readline("minishell $ ");
		if (str == NULL)
		{
			ft_printf("exit\n");
			break ;
		}
		else
		{	
			if (is_quote_close(str) == 1)
				printf("Quote is not closed\n");
			if (find_char(str, '|'))
				is_pipe(str);
			else
				no_pipe(str);
			add_history(str);
		}
	}
	free(str);
}

int	main(void)
{
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_minishell();
	return (0);
}
