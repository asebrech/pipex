/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:31:03 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/24 13:52:53 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"
# include <sys/errno.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_info
{
	int	one_fd[2];
	int	**fd;
	int	oui;
	char **path;
	int	nb_path;
	char **args;
	int	nb_arg;
	char **cmds;
	char **arg;
	char *file1;
	char *file2;
	char *end;
	char **env;
}				t_info;

void	ft_here_doc(t_info *info);
void	ft_file1(char **av, t_info *info);
void	fill_struct(int ac, char **av, char **env, t_info *info);
void	free_struct(t_info *info);
void	free_tab(char **tab);
void	exec_cmds(t_info *info);
void	ft_close_fd(t_info *info);
void	ft_here_doc(t_info *info);
void	last_pipe(t_info *info);

#endif
