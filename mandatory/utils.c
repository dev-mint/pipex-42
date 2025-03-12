/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:05:43 by anachat           #+#    #+#             */
/*   Updated: 2025/03/10 12:45:52 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_exists(char *path)
{
	if (access(path, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

char	*join_path(char *path, char *cmd)
{
	char	*cmd_path;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

static char	*get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd(char **paths, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cmd_path = join_path(paths[i], cmd);
		if (!cmd_path)
			return (ft_perr("allocation error"), NULL);
		if (cmd_exists(cmd_path))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*cmd_path;
	char	*env_path;
	char	**paths;

	if (ft_strchr(cmd, '/'))
	{
		if (!cmd_exists(cmd))
			return (NULL);
		return (ft_strdup(cmd));
	}
	env_path = get_env_path(env);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (ft_perr("allocation error"), NULL);
	cmd_path = find_cmd(paths, cmd);
	free_arr(paths);
	return (cmd_path);
}
