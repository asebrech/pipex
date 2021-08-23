/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:04:12 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:07 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	last_pipe(t_info *info)
{
	int	fd;

	fd = open(info->file2, O_RDWR | O_CREAT, 0777);
	dup2(fd, 1);
	close(fd);
	if (info->nb_arg != 1)
		dup2(info->fd[info->nb_arg - 2][0], 0);
}

void	first_pipe(t_info *info)
{
	int fd;

	if (!(ft_strncmp("here_doc", info->file1, ft_strlen(info->file1))))
	{
		ft_here_doc(info);
		dup2(info->one_fd[0], 0);
		close(info->one_fd[0]);
		close(info->one_fd[1]);
	}
	else
	{
		fd = open(info->file1, O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	if (info->nb_arg == 1)
		last_pipe(info);
	else
		dup2(info->fd[0][1], 1);
}

void	ft_pipe(t_info *info, int i)
{
	dup2(info->fd[i - 1][0], 0);
	dup2(info->fd[i][1], 1);
}

void	exec(t_info *info, int i)
{
	int	j;
	int	k;
	char	**tmp;
	char	*tmp2;
	char	*tmp3;

	j = 0;
	k = i * info->nb_path;
	while(j < info->nb_path)
	{
		tmp = ft_split((info->arg)[i], ' ');
		execve((info->cmds)[k + j], tmp, info->env);
		if (j == info->nb_arg - 1)
		free_tab(tmp);
		j++;
	}
	tmp = ft_split((info->arg)[i], ' ');
	tmp2 = ft_strjoin("pipex: command not found: ", *tmp);
	free_tab(tmp);
	tmp3 = ft_strjoin(tmp2, "\n");
	free(tmp2);
	ft_putstr_fd(tmp3, 2);
	free(tmp3);
}

void	exec_cmds(t_info *info)
{
	int	i;
	pid_t pid;

	i = 0;
	while (i < info->nb_arg)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				first_pipe(info);
			else if (i == info->nb_arg - 1)
				last_pipe(info);
			else
				ft_pipe(info, i);
			ft_close_fd(info);
			exec(info, i);
		}
		i++;
	}
	ft_close_fd(info);
	while(wait(NULL) > 0);
}
