/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:18:31 by anachat           #+#    #+#             */
/*   Updated: 2025/03/11 14:26:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	open_heredoc(int *fd)
{
	unlink("here_doc");
	fd[1] = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd[1] < 0)
		return (perror("cannot open here_doc file"), -1);
	fd[0] = open("here_doc", O_RDONLY);
	if (fd[0] < 0)
		return (perror("cannot open here_doc file"),
			close(fd[1]), unlink("here_doc"), -1);
	unlink("here_doc");
	return (0);
}

static void	ft_free_str(char *str)
{
	if (str)
		free(str);
}

static int	write_input(char *end, int *hd_fd)
{
	char	*line;
	int		len;

	if (open_heredoc(hd_fd) == -1)
		return (-1);
	write(1, "> ", 3);
	line = get_next_line(0);
	if (!line)
		return (write(1, "\n", 1), 0);
	while (line)
	{
		len = ft_strlen(line);
		line[len - 1] = '\0';
		if (ft_strncmp(line, end, ft_strlen(end) + 1) == 0)
			break ;
		line[len - 1] = '\n';
		ft_putstr_fd(line, hd_fd[1]);
		free(line);
		write(1, "> ", 3);
		line = get_next_line(0);
		if (!line)
			write(1, "\n", 1);
	}
	return (ft_free_str(line), 0);
}

int	is_heredoc(char *arg)
{
	if (ft_strncmp("here_doc", arg, 9) == 0)
		return (1);
	return (0);
}

int	file_check(char **av, int i, int *fd)
{
	int	hd_fd[2];
	int	infile;
	int	res;

	if (is_heredoc(av[1]) && i == 3)
	{
		res = write_input(av[2], hd_fd);
		if (res != 0)
			return (res);
		ft_dup2(hd_fd[0], 0);
		close(hd_fd[1]);
	}
	else if (!is_heredoc(av[1]) && i == 2)
	{
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
			return (perror("failed to open infile"),
				ft_dup2(fd[0], 0), -1);
		ft_dup2(infile, 0);
	}
	return (0);
}
