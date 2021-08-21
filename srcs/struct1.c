/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:11:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/20 14:45:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_here_doc()
{
	int	i;
	char *line;

	line = NULL;
	dup2(info->fd[0][1], 1);
	while(ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& get_next_line(line[i]) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
}

void	ft_file1(char **av, t_info *info)
{

	if (!(ft_strncmp("hear_doc", av[1], ft_strlen(av[1]))))
	{
		ft_here_doc(av, info);
		info->arg = &av[3];
		info->file1 = ft_strdup("hear_doc");
	}
	else
	{
		info->arg = &av[2];
		info->file1 = ft_strjoin("./", av[1]);
	}
}
