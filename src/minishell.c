/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/10 22:40:57 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//check si il y a un $ si oui renvoie 1 sinon renvoie 0
// static int	ft_ispth(char *str)
// {
// 	int	a;

// 	a = 0;
// 	while (str[a])
// 	{
// 		if (str[a] == '$')
// 			return (1);
// 		a++;
// 	}
// 	return (0);
// }

static void	no_pipe(const char *str)
{
	t_crust	*crust;
	char	**tab;

	crust = malloc(sizeof(t_crust));
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust || !crust->lst_cmd)
		return ;
	tab = ft_minisplit(str, ' ');
	ft_alloc_mantle(tab, crust->lst_cmd);
	print_core(crust->lst_cmd);
	return ;
}

static void	ft_space2crust(t_list *list)
{
	t_crust	*crust;
	char	**tab;

	crust = (t_crust *)list->content;
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust->lst_cmd)
		return ;
	tab = ft_minisplit(crust->input, ' ');
	ft_alloc_mantle(tab, crust->lst_cmd);
	print_core(crust->lst_cmd);
}

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
			// if (ft_ispth(crust->input) == 1)
			// {
			// 	crust->for_print = ft_print_path(crust->input);
			// 	ft_printf("%s\n", crust->for_print);
			// }
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
