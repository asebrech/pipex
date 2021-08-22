/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:11:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/22 10:47:51 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_here_doct(t_info *info)
{
	char *line;

	line = NULL;
	dup2(info->fd[0][0], 0);
	while(get_next_line(0, &line) > 0)
	{
		if (!(ft_strncmp(line, info->file1, ft_strlen(info->file1))))
			break ;
		else
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
	}
}

void	ft_file1(char **av, t_info *info)
{

	if (!(ft_strncmp("hear_doc", av[1], ft_strlen(av[1]))))
	{
		info->arg = &av[3];
		info->file1 = ft_strdup("hear_doc");
	}
	else
	{
		info->arg = &av[2];
		info->file1 = ft_strjoin("./", av[1]);
	}
}
