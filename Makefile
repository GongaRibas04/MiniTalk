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

LIBFT = ./libft/libft.a  

all: $(NAME1) $(NAME2)

$(LIBFT):
		$(MAKE)-C ./libft

$(NAME1): $(OBJS_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME1)

$(NAME2): $(OBJS_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME2)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(LIBFTPATH)$(LIBFT) $(NAME1) $(NAME2)

re:	fclean all
