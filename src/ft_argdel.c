/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:44 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:53:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

void			ft_argdel(void *content, size_t size)
{
	t_argument	*arg;

	TRACE;
	(void)size;
	if (content)
	{
		arg = (t_argument*)content;
		if (arg->name)
			ft_strdel(&arg->name);
		if (arg->value)
			ft_strdel(&arg->value);
		ft_memdel(&content);
	}
}
