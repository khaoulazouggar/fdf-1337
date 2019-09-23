# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 15:55:48 by kzouggar          #+#    #+#              #
#    Updated: 2019/09/20 17:23:25 by kzouggar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = checkfile.c\
draw.c\
ft_atoi.c\
ft_putstr.c\
ft_split_whitespaces.c\
ft_strcat.c\
ft_strchr.c\
ft_strcpy.c\
ft_strdel.c\
ft_strjoin.c\
ft_strlen.c\
ft_strnew.c\
ft_strsub.c\
get_next_line.c\
key_press.c\
main.c\
next_key.c\
next_press.c\
tools.c\
ft_memset.c\
color.c\
guide.c
CFLAG = -Wall -Wextra -Werror
mlx = gcc -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
NAME = fdf

all : $(NAME)
$(NAME) : $(OBJ)
	$(mlx) $(CFLAG) $^ -o $@ 
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
