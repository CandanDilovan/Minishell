/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/31 16:43:49 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(void)
{
	char	*test2;
	char 	*test3;

	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	while (1)
	{
		test2 = readline("minishell $ ");
		if (test2 == NULL)
			break ;
		else
		{
			if (ft_ispth(test2) == 1)
			{
				test3 = ft_print_path(test2);
				ft_printf("%s\n", test3);
			}
			add_history(test2);
		}
	}
	free(test2);
	return (0);
}
