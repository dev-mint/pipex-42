/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:48:20 by anachat           #+#    #+#             */
/*   Updated: 2025/03/11 13:40:40 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_close2(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

int	ft_dup2(int oldfd, int newfd)
{
	int	res;

	res = dup2(oldfd, newfd);
	close(oldfd);
	return (res);
}

void	ft_perr(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

int	ft_wait(pid_t last_pid, int default_st)
{
	int		status;
	int		exit_st;
	pid_t	pid;

	exit_st = default_st;
	pid = wait(&status);
	while (pid != -1)
	{
		if (pid == last_pid)
			exit_st = WEXITSTATUS(status);
		pid = wait(&status);
	}
	return (exit_st);
}
