/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:36:48 by anachat           #+#    #+#             */
/*   Updated: 2025/03/09 14:07:51 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	str_len(char *str);
char	*str_cut(char *s, unsigned int start, size_t len);
char	*str_clone(char *s1);
char	*str_concat(char *s1, char *s2);
char	*find_char(char *s, int c);

#endif