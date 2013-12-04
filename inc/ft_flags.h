/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:23:40 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/02 21:26:15 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS__H
# define FT_FLAGS__H

# include "ft_config.h"

typedef t_uint	t_flag;
typedef t_list	t_flags;

t_flags	*ft_flagsnew();
void	ft_flagset(t_flags **lst, t_flag base);
t_bool	ft_flagisset(t_flags *lst, t_flag base);
void	ft_flagsdel(t_flags **);
/*
int i=0;
char s[128];
char car;

car = 's';
while (i<128)
{
	((unsigned char*)s[i]) = (unsigned char)car;
	i++;
}
*/
#endif
