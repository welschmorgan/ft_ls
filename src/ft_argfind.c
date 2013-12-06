/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:54:59 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:55:11 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

t_list_iter		*ft_argfind(t_list *lst,
							const char *name,
							t_list_iter * last_iter)
{
	t_list_iter	*i;

	TRACE;
	i = ft_lstiternew(last_iter ? last_iter->start : lst);
	while (ft_lstitervalid(i))
	{
		if (ft_strequ(((t_argument*)i->head)->name, name))
			return (i);
		ft_lstiteradvance(i);
	}
	ft_lstiterdel(&i);
	return (NULL);
}
