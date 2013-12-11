/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:23:40 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/06 09:18:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS__H
# define FT_FLAGS__H

# include "ft_argument.h"

typedef enum	e_app_flags
{
	AF_NONE,
	AF_VERBOSE = 1 << 1,
	AF_LONG = 1 << 2,
	AF_REVERSE = 1 << 3,
	AF_RECURSE = 1 << 4,
	AF_ALL = 1 << 5,
	AF_SORT_MODTIME = 1 << 6
}				t_app_flags;

extern t_flags	g_flags;

#define SET_FLAG(flags,f) (flags |= f)
#define HAS_FLAG(flags,f) ((flags & f) != 0)


void			print_header(void);
void			raise_flags(t_list * elem);

#endif
