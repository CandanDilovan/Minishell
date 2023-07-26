/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/26 20:51:04 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*promptt;

	promptt = NULL;
	//rl_bind_key('\t', rl_complete);
	while (1)
	{
		promptt = readline("minishell $ ");
		if (!promptt)
			break ;
		ft_printf("prout");
		//add_history(promptt);
		//free(prompt);
	}
	return (0);
}
