/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:37:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/25 08:45:06 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_alloc(int ac, t_info *info)
{
	int	i;
	int	**fd;

	if (ac == 4)
		info->oui = 1;
	fd = malloc(sizeof(int *) * ac - 3);
	i = 0;
	while (i < ac - 3)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < (ac - 3))
	{
		pipe(fd[i]);
		i ++;
	}
	info->fd = fd;
}

int	main(int ac, char **av, char **env)
{
	t_info	info;

	if (ac >= 4)
	{
		ft_alloc(ac, &info);
		info.env = env;
		fill_struct(ac, av, env, &info);
		exec_cmds(&info);
		free_struct(&info);
	}
	else
	{
		printf("pipex need at least four arguments\n");
	}
	return (0);
}
