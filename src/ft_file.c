/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:30:32 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/11/30 11:39:26 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include "ft_config.h"
#include <dirent.h>
#include <sys/dir.h>

void	ft_file_set(t_file *f, char const *name)
{
	TRACE_FUNC;
	if (!f)
		return ;
	ft_strncpy(f->name, name, MAX_PATH);
}

t_file	*ft_file_new(char const *name)
{
	t_file	*ret;

	TRACE_FUNC;
	ret = ft_memalloc(sizeof(t_file));
	if (!ret)
		return (NULL);
	ft_file_set(ret, name);
	return (ret);
}

void	ft_file_del(t_file *f)
{
	TRACE_FUNC;
	if (!f)
		return ;
	if (f->name)
		ft_strdel(&f->name);
}

t_list	*ft_dir_scan(const char *dir,
					 t_file_filter filter,
					 t_file_compare compare)
{
	TRACE_FUNC;
	struct dirent	**namelist;
	int				n;

	n = scandir(dir, &namelist, NULL, compare);
	if (n < 0)
		g_last_error = AE_FILE_NOT_FOUND;
	else
	{
		while (n--)
		{
			PRINTL(namelist[n]->d_name);
			free (namelist[n]);
		}
	}
}
