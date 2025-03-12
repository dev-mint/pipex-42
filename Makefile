# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 15:24:35 by anachat           #+#    #+#              #
#    Updated: 2025/03/11 13:52:07 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   pipex
NAME_BONUS  =   pipex_bonus

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

LIBFT_DIR   =   lib/libft
GNL_DIR     =   lib/get_next_line

LIBFT_LIB   =   $(LIBFT_DIR)/libft.a

GNL_SRCS    =   $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRCS        =   mandatory/pipex.c mandatory/utils.c mandatory/utils2.c

SRCS_BONUS  =   bonus/pipex_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c \
				bonus/check_file_bonus.c $(GNL_SRCS)

OBJS        =   $(SRCS:.c=.o)
OBJS_BONUS  =   $(SRCS_BONUS:.c=.o)

all: $(LIBFT_DIR) $(NAME)

bonus: $(LIBFT_DIR) $(NAME_BONUS)

$(LIBFT_DIR):
	@make -C $(LIBFT_DIR)

mandatory/%.o: mandatory/%.c $(LIBFT_LIB) mandatory/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%_bonus.o: bonus/%_bonus.c $(LIBFT_LIB) bonus/pipex_bonus.h $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft -o $(NAME_BONUS)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: $(LIBFT_DIR)