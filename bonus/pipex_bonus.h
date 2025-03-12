/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:44:43 by anachat           #+#    #+#             */
/*   Updated: 2025/03/11 14:15:35 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

char	*get_path(char *cmd, char **env);
void	free_arr(char **arr);
int		ft_dup2(int oldfd, int newfd);
void	ft_close2(int fd1, int fd2);
void	ft_perr(char *str);
int		ft_wait(pid_t last_pid, int default_st);
int		file_check(char **av, int i, int *fd);
int		is_heredoc(char *arg);

#endif