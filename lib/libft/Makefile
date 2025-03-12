# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 17:41:09 by anachat           #+#    #+#              #
#    Updated: 2024/11/11 20:30:09 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFILES=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJECTS=$(CFILES:.c=.o)
BCFILES=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BOBJECTS=$(BCFILES:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<
	ar rcs $(NAME) $@

bonus: $(BOBJECTS)

clean:
	rm -rf $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
