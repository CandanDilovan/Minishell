/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/23 10:56:42 by dilovancand      ###   ########.fr       */
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

//pour déclarer le type
typedef enum s_type
{
	NO,
	CMD,
	FLAG,
	ARG,
}			t_type;

//contient chaque mot ainsi que son attribut, noyau du parsing
typedef struct s_core
{
	char	*str;
	t_type	type;
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
	char		*for_print;
	char		*input;
	char		*path;
	int			pipe;
	t_mantle	*lst_cmd;
}				t_crust;

//plus haute couche du parsing coupe la chaine au niveau des pipes
typedef struct s_space
{
	t_list	*crust;
	char	*input;
	char	**chatab;
	int		*tab;
}				t_space;

//struct qui gère les $path
typedef struct s_pathport
{
	char	*final;
	char	*pathifik;
	char	*pathion;
	char	*string1;
	char	*string2;
	int		f;
	char	c;
}			t_pathport;


//cmd cleaner
char	*ft_cmdisgood(char *str);

//minisplit
char	**ft_minisplit(char const *s, char c);
void	cpy(char *tab, char *s, int letters, int d);
int		issep(char str, char sep);
int		ft_count_tab(char *s, char c, int a, int tab_nb);
char	**free_all(char **tab, int a);

//list alloc
void	ft_alloc_mantle(char **tab, t_mantle *mantle);
void	ft_alloc_space(char **tab, t_space **space);

//parsing
void	ft_pipecount(char *str, t_space *space);
int		is_quote_close(char *str);
int		find_char(char	*tab, char c);
void	print_core(t_mantle *mantle);
int		ft_ispth(char *str);
int		ft_isquote(char *str);

//path handler
int		check_dollars(char str);
char	*ft_print_path(char *str, t_pathport *path);
int		ft_path_strlen(char *str, int b);

//signal handler
void	ft_sigint_handler(int si);
void	ft_sigquit_handler(int si);

#endif