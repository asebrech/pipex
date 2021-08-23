/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:11:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/23 10:39:30 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_here_doc(t_info *info)
{
	char *line;

	line = NULL;
	pipe(info->one_fd);
	while(get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, info->end, ft_strlen(info->end)))
			break ;
		ft_putstr_fd(line, info->one_fd[1]);
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
