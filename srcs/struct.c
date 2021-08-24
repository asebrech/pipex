/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 08:19:04 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/24 08:52:13 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **env)
{
    int i;

    i = 0;
    while(!(ft_strnstr(env[i], "PATH", ft_strlen(env[i]))))
        i++;
    return(ft_strnstr(env[i], "PATH", ft_strlen(env[i])) + 5);
}

void	make_str1(char **arg, char *args)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (arg[i])
	{
		j = 0;
		while(arg[i][j])
		{
			args[k] = arg[i][j];
			k++;
			j++;
		}
		args[k] = ' ';
		k++;
		i++;
	}
	args[k] = '\0';
}

char 	*make_str(char **arg)
{
	int	i;
	int	len;
	char	*args;

	len = 0;
	i = 0;
	while (arg[i])
	{
		len += ft_strlen(arg[i]) + 1;
		i++;
	}
	args = malloc(sizeof(char *) * len + 1);
	make_str1(arg, args);
	return (args);
}

void	fill_cmds(t_info *info)
{
	int	i;
	int	j;
	int	k;
	char **tmp;
	char *tmp2;

	info->cmds = malloc(sizeof(char *) * (info->nb_arg * info->nb_path) + 1);
	i = 0;
	k = 0;
	while (i < info->nb_arg)
	{
		j = 0;
		while (j < info->nb_path)
		{
			tmp = ft_split((info->arg)[i], ' ');
			tmp2 = ft_strjoin(info->path[j], "/");
			info->cmds[k] = ft_strjoin(tmp2, *tmp);
			free(tmp2);
			free_tab(tmp);
			j++;
			k++;
		}
		i++;
	}
	info->cmds[k] = NULL;
}

void    fill_struct(int ac, char **av, char **env, t_info *info)
{
    char *tmp;
	int	i;

	tmp = NULL;
	ft_file1(av, info);
	info->file2 = ft_strjoin("./", av[ac - 1]);
	av[ac - 1] = NULL;
	i = 0;
	while((info->arg)[i])
		i++;
	info->nb_arg = i;
	tmp = make_str(info->arg);
	info->args = ft_split(tmp, ' ');
	free(tmp);
    info->path = ft_split(find_path(env), ':');
	i = 0;
	while((info->path)[i])
		i++;
	info->nb_path = i;
	fill_cmds(info);
}
