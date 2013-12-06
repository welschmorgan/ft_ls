/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 09:22:52 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 10:20:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_memrealloc.h"

void		*ft_memrealloc(void *content, size_t size)
{
	void	*ptr;

	ptr = ft_memalloc(size);
	if (ptr)
		ft_memcpy(ptr, content, size);
	if (content)
		ft_memdel(&content);
	return (ptr);
}
