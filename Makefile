#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/11/28 23:11:35 by darkboss         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

INC = ./inc -I../../algo_001/libft
SRC_DIR = ./src
UNITS = main.c ft_commands.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -g -std=c89 -O3

all: $(NAME)

.PHONY: clean fclean all re tests

$(NAME): $(UNITS_O)
	@$(CC) -o $(NAME) $^

%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c -I$(INC) -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re: fclean all