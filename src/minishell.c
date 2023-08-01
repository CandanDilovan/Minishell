/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/01 16:57:22 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//check si il y a un $ si oui renvoie 1 sinon renvoie 0
static int	ft_ispth(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '$')
			return (1);
		a++;
	}
	return (0);
}

//boucle infini, affiche le prompt et gère les arguments envoyer
void	ft_minishell(void)
{
	t_crust	*crust;

	crust = malloc(sizeof(t_crust));
	if (!crust)
		return ;
	while (1)
	{
		crust->input = readline("minishell $ ");
		if (crust->input == NULL)
		{
			ft_printf("exit\n");
			break ;
		}
		else
		{	
			if (is_quote_close(crust->input) == 1)
				printf("Quote is not closed\n");
			if (ft_ispth(crust->input) == 1)
			{
				crust->for_print = ft_print_path(crust->input);
				ft_printf("%s\n", crust->for_print);
			}
			add_history(crust->input);
		}
	}
	free(crust->input);
}

int	main(void)
{
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_minishell();

	return (0);
}
