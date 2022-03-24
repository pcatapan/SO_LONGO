# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 07:28:35 by pcatapan          #+#    #+#              #
#    Updated: 2022/03/24 09:40:40 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# SRCS = ./src/*.c ./PRINTF/*.c ./src/move_element/*.c
SRCS = ./src/main.c ./src/map.c ./src/checker_map.c ./src/checker_content_map.c ./src/utils.c ../PRINTF/BONUS/*.c 


OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

# KIT = -l mlx -framework openGL -framework AppKit


$(NAME) :
	$(CC) -g $(SRCS) $(KIT)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -rf $(NAME) 
	rm -rf a.*
	rm -rf *.dSYM

norm:
	norminette -R $(SRCS:.c)
