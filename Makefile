#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/12/01 03:04:54 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
LIBFT = ../libft/
LIBS = -L$(LIBFT) -lft
INC = ./inc -I$(LIBFT)
SRC_DIR = ./src
UNITS = main.c ft_commands.c ft_config.c ft_file.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -g -std=c89 -O3 -D_DEBUG

all: $(NAME)

.PHONY: clean fclean all re tests

$(NAME): $(UNITS_O)
	@$(CC) -o $(NAME) $^ $(LIBS)

%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c -I$(INC) -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re: fclean all
