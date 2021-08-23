/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:44:13 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:50 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	while(i < info->nb_arg)
	{
		free(info->fd[i]);
		i++;
	}
	free(info->fd);
}

void	ft_close_fd(t_info *info)
{
	int i;

	i = 0;
	while(i < info->nb_arg)
	{
		close(info->fd[i][0]);
		close(info->fd[i][1]);
		i++;
	}
}
