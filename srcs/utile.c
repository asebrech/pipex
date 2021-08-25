/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:44:13 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/25 08:50:01 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_here_doc(t_info *info)
{
	char	*line;

	line = NULL;
	if (info->oui == 1)
	{
		info->one_fd[1] = open(info->file2, O_RDWR | O_CREAT, 0777);
		dup2(info->one_fd[1], 1);
	}
	else
		pipe(info->one_fd);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, info->end, ft_strlen(info->end)))
			break ;
		ft_putstr_fd(line, info->one_fd[1]);
		ft_putstr_fd("\n", info->one_fd[1]);
		free(line);
		line = NULL;
	}
}

void	ft_file1(char **av, t_info *info)
{
	if (!(ft_strncmp("here_doc", av[1], ft_strlen(av[1]))))
	{
		info->end = av[2];
		info->arg = &av[3];
		info->file1 = ft_strdup(av[1]);
	}
	else
	{
		info->arg = &av[2];
		info->file1 = ft_strjoin("./", av[1]);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_struct(t_info *info)
{
	int	i;

	free(info->file1);
	free(info->file2);
	free_tab(info->args);
	free_tab(info->path);
	free_tab(info->cmds);
	i = 0;
	while (i < info->nb_arg)
	{
		free(info->fd[i]);
		i++;
	}
	free(info->fd);
}

void	ft_close_fd(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_arg)
	{
		close(info->fd[i][0]);
		close(info->fd[i][1]);
		i++;
	}
}
