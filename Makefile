# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 14:07:55 by vdaemoni          #+#    #+#              #
#    Updated: 2020/02/25 17:22:19 by vdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_INCLUDES = libft/includes
SRCS =  ./srcs/ls.c \
		./srcs/helpo.c \
		./srcs/long_out.c \
		./srcs/printo.c \
		./srcs/sorto.c \
		./srcs/bufo.c \
		./srcs/algos.c \
		./srcs/cmps.c \
		./srcs/errors.c \
		./srcs/ag_sorto.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = includes

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft
%.o: %.c
		$(CC) $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@ -c $<

clean :
		/bin/rm -f $(OBJS)
		make -C $(LIBFT) clean

fclean : clean
		/bin/rm -f $(NAME)
		make -C $(LIBFT) fclean

re : fclean all