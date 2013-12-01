/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:27:04 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/01 03:01:46 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE__H
# define FT_FILE__H

# include <libft.h>

typedef struct		s_file
{
	char			*name;
}					t_file;

t_file	*ft_file_new(char const *name);
void	ft_file_del(t_file *f);
void	ft_file_set(t_file *f, char const *name);

#endif
