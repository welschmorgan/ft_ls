/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:01 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:52:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

t_argument		*ft_argset(t_argument *arg
						   , const char *name
						   , const char *value
						   , t_flags type)
{
	TRACE;
	if (!arg)
		return (NULL);
	if (arg->name)
		ft_strdel(&arg->name);
	if (arg->value)
		ft_strdel(&arg->value);
	arg->type = type;
	arg->name = ft_strdup(name);
	arg->value = ft_strdup(value);
	return (arg);
}
