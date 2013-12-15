#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2013/12/15 23:37:29 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
LIBFT = ./libft
INC = ./include -I$(LIBFT)
SRC_DIR = ./src
UNITS = main.c ft_file.c ft_argadd.c ft_argdel.c ft_argparse.c ft_argfind.c\
		ft_argnew.c ft_argset.c ft_list_iter.c ft_flags.c ft_memrealloc.c

UNITS_O = $(UNITS:.c=.o)
UNITS_O_D = $(UNITS:.c=.d.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,%,$(UNITS_O))
OBJS_D = $(patsubst %,%,$(UNITS_O_D))
LDFLAGS = -L$(LIBFT) -lft
CFLAGS_D = -Wall -Wextra -Werror -std=c89 -g3 -D_DEBUG
CFLAGS = -Wall -Wextra -Werror -std=c89 -O3

all: release

all_d: debug

clean_deps:
	make clean -C $(LIBFT)

fclean_deps:
	make fclean -C $(LIBFT)

deps:
	make -C $(LIBFT)

$(NAME): $(UNITS_O) $(LIBFT)/libft.a
	$(CC) -o $(NAME) $^ $(LDFLAGS)

$(NAME)_d: $(UNITS_O_D) $(LIBFT)/libft.a
	$(CC) -o $(NAME)_d $^ $(LDFLAGS)

%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c -I$(INC) -o $@ $<

%.d.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS_D) -c -I$(INC) -o $@ $<

clean: clean_deps
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(OBJS_D)

fclean : clean fclean_deps
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME)_d

re: fclean release

release: deps $(NAME)
debug: deps $(NAME)_d

.PHONY: clean fclean all re clean_deps fclean_deps deps release debug all_d
