/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:27:04 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/11/30 11:04:53 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE__H
# define FT_FILE__H

# include <libft.h>

typedef struct		s_file
{
	char			*name;
}					t_file;

struct dirent;
typedef int (*t_file_filter)(const struct dirent*);
typedef int (*t_file_compare)(const struct dirent **, const struct dirent **);

t_file	*ft_file_new(char const *name);
void	ft_file_del(t_file *f);
void	ft_file_set(t_file *f, char const *name);
t_list	*ft_dir_scan(const char *dir,
					 t_file_filter filter,
					 t_file_compare compare);

#endif
