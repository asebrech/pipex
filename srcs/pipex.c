/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:37:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/17 16:49:20 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **env)
{
	t_info	info;
	int	i;
	int	**fd;

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
	info.fd = fd;
	info.env = env;
    fill_struct(ac, av, env, &info);
	exec_cmds(&info);
	free_struct(&info);
    return (0);
}