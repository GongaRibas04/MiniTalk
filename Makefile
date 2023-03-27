# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 16:09:44 by gobarbos          #+#    #+#              #
#    Updated: 2023/03/23 16:14:25 by gobarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1 = client

NAME2 = server

CLIENT = ft_client/main.c 

SERVER = ft_server/main.c 

OBJS_CLIENT=$(CLIENT:.c=.o)

OBJS_SERVER=$(SERVER:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror

LIBFTPATH = ./libft/

LIBFT = libft.a 

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_CLIENT)
		make -C $(LIBFTPATH)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFTPATH)$(LIBFT) -o $(NAME1)

$(NAME2): $(OBJS_SERVER)
		make -C $(LIBFTPATH)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFTPATH)$(LIBFT) -o $(NAME2)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	cd libft && $(MAKE) clean

fclean:	clean
	rm -f $(LIBFTPATH)$(LIBFT) $(NAME1) $(NAME2)

re:	fclean all
