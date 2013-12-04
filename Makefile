#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/12/04 15:15:56 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
LIBFT = ../libft
LIBOPT = ../libopt
LIBS = -L$(LIBFT) -L$(LIBOPT) -lft -lopt
INC = ./inc -I$(LIBFT) -I$(LIBOPT)
SRC_DIR = ./src
UNITS = main.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -g -std=c89 -O3 -D_DEBUG

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(LIBOPT)/libopt.a:
	$(MAKE) -C $(LIBOPT)

build_deps: $(LIBFT)/libft.a $(LIBOPT)/libopt.a

clean_deps:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(LIBOPT)

fclean_deps:
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(LIBOPT)

all: $(NAME) build_deps

.PHONY: clean fclean all re tests build_deps

$(NAME): $(UNITS_O) $(LIBFT)/libft.a $(LIBOPT)/libopt.a
	@$(CC) -o $(NAME) $^ $(LIBS)

%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c -I$(INC) $(LIBS) -o $@ $<

clean: clean_deps
	@/bin/rm -f $(OBJS)

fclean : clean fclean_deps
	@/bin/rm -f $(NAME)

re: fclean all
