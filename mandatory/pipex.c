/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:49:00 by anachat           #+#    #+#             */
/*   Updated: 2025/03/11 14:00:06 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_child1(int *fd, char *path, char **cmd, char **env)
{
	pid_t	id;

	id = fork();
	if (id < 0)
		return (perror("fork failed"), ft_dup2(fd[0], 0), 1);
	if (id == 0)
	{
		close(fd[3]);
		close(fd[4]);
		ft_dup2(fd[2], 0);
		close(fd[0]);
		ft_dup2(fd[1], 1);
		if (execve(path, cmd, env) == -1)
		{
			perror("execve 1 failed");
			exit(1);
		}
		return (0);
	}
	else
		return (close(fd[1]), ft_dup2(fd[0], 0), close(fd[2]), 0);
}

static int	parent1(int *fd, char **av, char **env)
{
	char	**cmd;
	char	*path;

	if (pipe(fd) < 0)
		return (perror("pipe failed"), 1);
	fd[2] = open(av[1], O_RDONLY);
	if (fd[2] < 0)
		return (perror("failed to open infile"),
			close(fd[1]), ft_dup2(fd[0], 0), 1);
	if (!*(av[2]))
		return (ft_perr("command not found"), close(fd[1]),
			close(fd[2]), ft_dup2(fd[0], 0), 1);
	cmd = ft_split(av[2], ' ');
	if (!cmd)
		return (ft_perr("allocation error"), close(fd[1]),
			close(fd[2]), ft_dup2(fd[0], 0), 1);
	path = get_path(cmd[0], env);
	if (!path)
		return (perror("command not found"), free_arr(cmd),
			close(fd[1]), close(fd[2]), ft_dup2(fd[0], 0), 1);
	exec_child1(fd, path, cmd, env);
	return (free_arr(cmd), close(fd[1]), close(fd[0]),
		close(fd[2]), free(path), 0);
}

static pid_t	exec_child2(int *fd, char *path, char **cmd, char **env)
{
	pid_t	id;

	id = fork();
	if (id < 0)
		return (close(fd[5]), 1);
	if (id == 0)
	{
		ft_close2(fd[3], fd[4]);
		ft_dup2(fd[5], 1);
		if (execve(path, cmd, env) == -1)
			return (perror("execve 2 failed"), free_arr(cmd),
				free(path), exit(1), id);
	}
	return (id);
}

static int	parent2(int *fd, char **av, char **env, pid_t *pid)
{
	char	*path;
	char	**cmd;

	fd[5] = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[5] < 0)
		return (perror("error opening outfile"), 1);
	if (!*(av[3]))
		return (ft_perr("command not found"), close(fd[5]), 1);
	cmd = ft_split(av[3], ' ');
	if (!cmd)
		return (ft_perr("allocation error"), close(fd[5]), 1);
	path = get_path(cmd[0], env);
	if (!path)
		return (perror("command not found"), free_arr(cmd), close(fd[5]), 1);
	*pid = exec_child2(fd, path, cmd, env);
	return (free_arr(cmd), free(path), close(fd[5]), 0);
}

int	main(int ac, char **av, char **env)
{
	pid_t	last_pid;
	int		exit_st;
	int		fd[6];

	if (ac != 5)
		return (ft_perr("invalid args count"), 1);
	fd[3] = dup(0);
	fd[4] = dup(1);
	parent1(fd, av, env);
	exit_st = parent2(fd, av, env, &last_pid);
	ft_dup2(fd[3], 0);
	ft_dup2(fd[4], 1);
	return (ft_wait(last_pid, exit_st));
}
