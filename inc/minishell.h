/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/07 16:44:57 by dilovancand      ###   ########.fr       */
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

//contient chaque mot ainsi que c'est attribut, noyau du parsing
typedef struct s_core
{
	char	*str;
	int		flag;
	int		cmd;
}			t_core;

//contient le début de la liste chainée et le nombre de liste
typedef struct s_mantle
{
	t_list	*first;
	int		list_nb;
}			t_mantle;

//couche exterieur du parsing contient 
typedef struct s_crust
{
	char		*input;
	char		*for_print;
	char		*path;
	t_mantle	*lst_pars;
	t_mantle	*lst_cmd;
}				t_crust;

//struct qui gère les $path
typedef struct s_pathport
{
	char	*final;
	char	*pathifik;
	char	*pathion;
	char	*string1;
	char	*string2;
}			t_pathport;


//cmd cleaner
char	*ft_cmdisgood(char *str);

//minisplit
char	**ft_minisplit(char const *s, char c);
void	cpy(char *tab, char *s, int letters, int d);
int		issep(char str, char sep);
int		ft_count_tab(char *s, char c, int a, int tab_nb);
char	**free_all(char **tab, int a);

//parsing
int		is_quote_close(char *str);

//path handler
char	*ft_print_path(char *str);
int		ft_path_strlen(char *str, int b);

//signal handler
void	ft_sigint_handler(int si);
void	ft_sigquit_handler(int si);

#endif