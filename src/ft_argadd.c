/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:53:08 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:54:04 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

t_argument		*ft_argadd(t_list **lst
						   , const char *name
						   , const char *value
						   , t_flags type)
{
	t_argument *new;

	TRACE;
	new = ft_argnew(name, value, type);
	if (!new)
		return (new);
	ft_lstadd(lst, ft_lstnew(new, sizeof(t_argument)));
	return (new);
}
