/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:47:33 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/05 23:48:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_ITER__H
# define FT_LIST_ITER__H

# include <libft.h>

typedef struct	s_list_iter
{
	t_list		*head;
	t_list		*start;
	t_list		*end;
}				t_list_iter;

void			ft_lstiterset(t_list_iter *iter, t_list *list);
t_list_iter		*ft_lstiternew(t_list *list);
void			ft_lstiterdel(t_list_iter **lst);


t_list			*ft_lstbegin(t_list *l);
t_list			*ft_lstend(t_list *l);
t_bool			ft_lstitervalid(t_list_iter *it);
t_bool			ft_lstiteradvance(t_list_iter *it);

#endif
