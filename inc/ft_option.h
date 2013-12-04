/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:04:36 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/02 20:07:41 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION__H
# define FT_OPTION__H

# include <libft.h>
# include "ft_config.h"
# include "ft_flags.h"

typedef enum		e_app_flag
{
	AF_NONE,
	AF_ALL = 1 << 1,
	AF_LONG = 1 << 2,
	AF_RECURSIVE = 1 << 3,
	AF_REVERSE = 1 << 4,
	AF_SORT_MODTIME = 1 << 5,
	AF_VERBOSE		= 1 << 6
}					t_app_flag;

extern t_flags		*g_app_flags;

/*
 * Free args are char*
 * Flags are t_uint*
 */
typedef struct		s_arglist
{
	t_list			*free;
	t_flags			*flags;
}					t_arglist;

typedef void (*t_free_arg_inserter)(t_list **, char*);
typedef void (*t_flag_inserter)(t_flags **, char*);

void		print_elem(t_list *elem);
int			do_scan(char *dir, t_flags *flags);
int			check_app_flags(char c, char *str);
t_arglist	*parse_commands( int count,
							 char **array,
							 t_free_arg_inserter free_ins,
							 t_flag_inserter flag_ins);
int			parse_errors(int errors);

#endif /* !FT_OPTION__H */
