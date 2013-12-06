/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:12 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 11:50:25 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <libft.h>

#include "ft_file.h"
#include "ft_flags.h"
#include "ft_list_iter.h"
#include "ft_argument.h"
#include "ft_debug.h"

static char		*find_pwuid(size_t uid)
{
	char			*name;
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd)
		name = ft_strdup(pwd->pw_name);
	else
		name = ft_strdup(ft_itoa((int)uid));
	return (name);
}

static char		*find_gruid(size_t uid)
{
	char			*name;
	struct group	*pwd;

	pwd = getgrgid(uid);
	if (pwd)
		name = ft_strdup(pwd->gr_name);
	else
		name = ft_strdup(ft_itoa((int)uid));
	return (name);
}
void			print_dir(t_list *list)
{
	while (list)
	{
		if (list->content)
		{
			if (HAS_FLAG(g_flags, AF_LONG))
				print_long_dir(((t_file*)list->content));
			else
			{
				ft_putstr(((t_file*)list->content)->name);
				if (list->next)
					ft_putstr(" ");
			}
		}
		list = list->next;
	}
}

static void		swap_ptr(void **a, void **b)
{
	void		*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool	is_sorted(t_list *list)
{
	while (list)
	{
		if (list->content && list->next && list->next->content)
		{
			if (HAS_FLAG(g_flags, AF_REVERSE)
				&& ft_strcmp(((t_file*)list->content)->name,
							 ((t_file*)list->next->content)->name) < 0)
				return (FALSE);
			else if (!HAS_FLAG(g_flags, AF_REVERSE)
					 && ft_strcmp(((t_file*)list->content)->name,
							 ((t_file*)list->next->content)->name) > 0)
				return (FALSE);
		}
		list = list->next;
	}
	return (TRUE);
}

static void		sort_dir(t_list *list)
{
	int	code;

	while (list)
	{
		if (list->content)
		{
			if (list->next && list->next->content)
			{
				code = ft_strcmp(((t_file*)list->content)->name,
								 ((t_file*)list->next->content)->name);

				if ((HAS_FLAG(g_flags, AF_REVERSE) && code < 0)
					|| (!HAS_FLAG(g_flags, AF_REVERSE) && code > 0))
					swap_ptr(&list->content, &list->next->content);
			}
		}
		list = list->next;
	}
}

#define ISDOTDOT(str) (ft_strequ(str, ".") || ft_strequ(str, ".."))

void			scan_dir(t_list *elem)
{
	DIR				*handle;
	struct dirent	*entry;
	t_argument		*arg;
	t_list			*ret;
	t_file			*new;

	if (!elem || !elem->content)
		return ;
	arg = ((t_argument*)elem->content);
	if (!HAS_FLAG(arg->type, AT_FREE))
		return ;
	ret = ft_lstnew(NULL, 0);
	if (HAS_FLAG(g_flags, AF_VERBOSE))
	{
		ft_putstr("Scanning dir: ");
		ft_putendl(arg->name);
	}
	handle = opendir(arg->name);
	if (!handle)
	{
		perror("opendir");
		return ;
	}
	while ((entry = readdir(handle)))
	{
		if (!ISDOTDOT(entry->d_name)
			|| (ISDOTDOT(entry->d_name) && HAS_FLAG(g_flags, AF_ALL)))
		{
			new = ft_filenew("", "", "");
			if (new->name)
				ft_strdel(&new->name);
			new->name = ft_strnew(ft_strlen(arg->name)
								  + ft_strlen("/")
								  + ft_strlen(entry->d_name));
			ft_strcpy(new->name, arg->name);
			ft_strcat(new->name, "/");
			ft_strcat(new->name, entry->d_name);
			if (!new)
			{
				perror("ft_filenew");
				continue ;
			}
			if (lstat(new->name, new->infos) == -1)
			{
				perror(new->name);
				continue ;
			}
			ft_fileset(new,
					   entry->d_name,
					   find_gruid(new->infos->st_gid),
					   find_pwuid(new->infos->st_uid));
			ft_lstadd(&ret, ft_lstnew(new, sizeof(t_file)));
		}
	}
	closedir(handle);
	while (!is_sorted(ret))
	{
		sort_dir(ret);
	}
	print_dir(ret);
	ft_lstdel(&ret, ft_argdel);
}

int				main(int argc, char **argv)
{
	t_list	*list;

	list = ft_argparse(argc, argv);
	if (list)
	{
		if (!list->next)
			ft_argadd(&list, ".", "", AT_FREE);
		ft_lstiter(list, raise_flags);
		print_header();
		ft_lstiter(list, scan_dir);
		ft_lstdel(&list, ft_argdel);
	}
	return (0);
}
