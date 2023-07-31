/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/30 20:58:48 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_pathport
{
	char	*final;
	char	*pathifik;
	char	*pathion;
	char	*string1;
	char	*string2;
}			t_pathport;

//path handler
char	*ft_print_path(char *str);
int		ft_path_strlen(char *str, int b);

//signal handler
void	ft_sigint_handler(int si);
void	ft_sigquit_handler(int si);

#endif