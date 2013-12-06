#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/12/06 09:59:38 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
LIBFT = ./libft
LIBS = -L$(LIBFT) -lft
INC = ./inc -I$(LIBFT) -I$(LIBOPT) -I$(LIBOPT)/inc
SRC_DIR = ./src
UNITS = main.c ft_file.c ft_argadd.c ft_argdel.c ft_argparse.c ft_argfind.c\
		ft_argnew.c ft_argset.c ft_list_iter.c ft_flags.c ft_memrealloc.c

UNITS_O = $(UNITS:.c=.o)
UNITS_OD = $(UNITS:.c=_d.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
OBJSD = $(patsubst %,%,$(UNITS_OD))
FLAGS = -Wall -Wextra -Werror -std=c89
RFLAGS = $(FLAGS) -O3
DFLAGS = $(FLAGS) -g -D_DEBUG

all: debug

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

build_deps: $(LIBFT)/libft.a

clean_deps:
	$(MAKE) clean -C $(LIBFT)

fclean_deps:
	$(MAKE) fclean -C $(LIBFT)

debug: $(NAME)_d build_deps
release: $(NAME) build_deps

.PHONY: clean fclean all re tests build_deps\
	debug release clean_deps fclean_deps

$(NAME): $(UNITS_O) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $^ $(LIBS)

$(NAME)_d: $(UNITS_OD) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $^ $(LIBS)

%.o: $(SRC_DIR)/%.c
	@$(CC) $(RFLAGS) -c -I$(INC) $(LIBS) -o $@ $<

%_d.o: $(SRC_DIR)/%.c
	@$(CC) $(DFLAGS) -c -I$(INC) $(LIBS) -o $@ $<

clean: clean_deps
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(OBJSD)

fclean : clean fclean_deps
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME)_d

re: fclean all
