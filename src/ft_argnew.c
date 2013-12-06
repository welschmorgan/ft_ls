/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:23 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:53:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

t_argument		*ft_argnew(const char *name, const char *value, t_flags type)
{
	t_argument	*arg;

	TRACE;
	arg = ft_memalloc(sizeof(t_argument));
	arg->name = NULL;
	arg->value = NULL;
	ft_argset(arg, name, value, type);
	return (arg);
}
