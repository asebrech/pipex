# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/08/20 10:25:17 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
NAME = pipex
RM = rm -rf
SRC =	srcs/pipex.c\
		srcs/struct.c\
		srcs/struct1.c\
		srcs/utile.c\
		srcs/exec_cmds.c\
		get_next_line/get_next_line_utils.c\
		get_next_line/get_next_line.c
SRCB =

ifdef WHITH_BONUS
	OBJ = $(SRCB:.c=.o)
else
	OBJ = $(SRC:.c=.o)
endif

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

bonus :
	@make WHITH_BONUS=1 all

$(NAME) : $(OBJ)
	@make -C libft bonus
	$(CC) $(CFLAGS) -I$(HEADER) -Llibft -lft $(OBJ) -o $(NAME)

clean :
	@make -C libft clean
	$(RM) */*.o

fclean : clean
	$(RM) libft/libft.a
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re bonus
