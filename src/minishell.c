/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/26 23:46:19 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*test_prompt(char *str)
{
	char	*prompt;

	prompt = malloc(sizeof(char) * (ft_strlen(str) + 1));
	strcpy(prompt, str);
	return (prompt);
}

int	main(void)
{
	char	*test;
	char	*test2;

	test = test_prompt("minishell $ ");
	rl_bind_key('\t', rl_complete);
	while (1)
	{
		test2 = readline(NULL);
		printf("%s", test);
		if (test2 == NULL)
			break ;
		else
		{
			add_history(test2);
		}
	}
	return (0);
}
