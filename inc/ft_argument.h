/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:43:47 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:29:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ARGUMENT__H
# define FT_ARGUMENT__H

#include <libft.h>
#include "ft_list_iter.h"

typedef enum	e_type
{
	AT_NONE = 0,
	AT_SHORT = 1 << 1,
	AT_LONG = 1 << 2,
	AT_VALUE = 1 << 3,
	AT_FREE = 1 << 4,
	AT_SHORT_VALUE = AT_VALUE | AT_SHORT,
	AT_LONG_VALUE = AT_VALUE | AT_LONG
}				t_type;

typedef t_uint	t_flags;

typedef struct	s_argument
{
	char		*name;
	char		*value;
	t_flags		type;
}				t_argument;

t_argument		*ft_argnew(const char *name, const char *value, t_flags type);
t_argument		*ft_argadd(t_list **lst
						   , const char *name
						   , const char *value
						   , t_flags type);
t_argument		*ft_argset(t_argument *arg
						   , const char *name
						   , const char *value
						   , t_flags type);
void			ft_argdel(void *content, size_t size);
t_list			*ft_argparse(int c, char **r);
t_list_iter		*ft_argfind(t_list *lst,
							const char *name,
							t_list_iter * last_iter);

#endif
