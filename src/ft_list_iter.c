/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:50:22 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 01:50:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_iter.h"
#include "ft_debug.h"

void			ft_lstiterset(t_list_iter *iter, t_list *list)
{
	TRACE;
	if (!iter)
		return ;
	iter->head = list;
	iter->start = list;
	iter->end = list;
	while (iter && iter->end)
	{
		if (!iter->end->next)
			break ;
		iter->end = iter->end->next;
	}
}

t_list_iter		*ft_lstiternew(t_list *list)
{
	t_list_iter	*iter;

	TRACE;
	iter = ft_memalloc(sizeof(t_list_iter));
	if (!iter)
		return (NULL);
	ft_lstiterset(iter, list);
	return (iter);
}

void			ft_lstiterdel(t_list_iter **lst)
{
	TRACE;
	if (lst && *lst)
		ft_memdel((void**)lst);
}

t_list			*ft_lstbegin(t_list *l)
{
	TRACE;
	return (l ? l->next : NULL);
}

t_list			*ft_lstend(t_list *lst)
{
	t_list	*p;

	TRACE;
	p = lst;
	while (p)
	{
		if (p->next)
			return (p);
		p = p->next;
	}
	return (p);
}

t_bool			ft_lstitervalid(t_list_iter *it)
{
	TRACE;
	return (it && it->head != it->end);
}

t_bool			ft_lstiteradvance(t_list_iter *it)
{
	TRACE;
	if (ft_lstitervalid(it))
	{
		it->head = it->head->next;
		return (TRUE);
	}
	return (FALSE);
}

