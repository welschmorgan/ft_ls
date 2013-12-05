/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:12 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/05 03:14:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <libopt.h>
#include <libft.h>

#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_file.h"
#include "main.h"

#define LSTEMPTY(lst) (!(lst && lst->next))
#define ISDOTORDOTDOT(x) (ft_strequ(x, ".") || ft_strequ(x, ".."))
#define HASFLAG(flag) ((flag & g_flags) != AF_NONE)

t_flags			g_flags = AF_NONE;

void			raise_flag(char *arg, t_uint flags)
{
	(void)flags;
	if (ft_strequ(arg, "-a") || ft_strequ(arg, "--all"))
		g_flags |= AF_ALL;
	if (ft_strequ(arg, "-v") || ft_strequ(arg, "--verbose"))
		g_flags |= AF_VERBOSE;
	if (ft_strequ(arg, "-l"))
		g_flags |= AF_LONG;
	if (ft_strequ(arg, "-R") || ft_strequ(arg, "--recursive"))
		g_flags |= AF_RECURSE;
	if (ft_strequ(arg, "-r") || ft_strequ(arg, "--reverse"))
		g_flags |= AF_REVERSE;
	if (ft_strequ(arg, "-t"))
		g_flags |= AF_SORT_MODTIME;
}
void		print_dir(t_list *lst)
{
	size_t	col;
	t_bool	new_line;

	new_line = FALSE;
	col = 0;
	while (lst)
	{
		if (col >= 20)
		{
			ft_putendl("");
			col = 0;
		}
		if (lst->content)
		{
			if (HASFLAG(AF_LONG))
			{
				print_long_dir((t_file*)lst->content);
			}
			else
			{
				new_line = TRUE;
				PRINT(((t_file*)lst->content)->name);
				if (lst->next && lst->next->content)
					PRINT("  ");
			}
		}
		col ++;
		lst = lst->next;
	}
	if (new_line)
		PRINTL("");
}

static void		print_header(void)
{
	if ((g_flags & AF_VERBOSE) != AF_NONE)
	{
		PRINT("Show hidden files: ");
		PRINTL(((g_flags & AF_ALL) != AF_NONE) ? "true" : "false");
		PRINT("Long listing format: ");
		PRINTL(((g_flags & AF_LONG) != AF_NONE) ? "true" : "false");
		PRINT("Recursive: ");
		PRINTL(((g_flags & AF_RECURSE) != AF_NONE) ? "true" : "false");
		PRINT("Reversed order: ");
		PRINTL(((g_flags & AF_REVERSE) != AF_NONE) ? "true" : "false");
	}
}

static void		delete_dir(void *content, size_t size)
{
	(void)size;
	ft_filedel((t_file**)&content);
}
void			scan_dir(char const *dir)
{
	DIR				*handle;
	struct dirent	*entry;
	struct stat		infos;
	t_list			*lst;
	struct passwd	*puid;
	struct group	*guid;
	print_header();
	lst = ft_lstnew(NULL, 0);
	if (dir != NULL)
	{
		if ((handle = opendir(dir)) == NULL)
		{
			perror("opendir");
			return ;
		}
		while ((entry = readdir(handle)) != NULL)
		{
			puid = getpwuid(infos.st_uid);
			guid = getgrgid(infos.st_gid);
			lstat(entry->d_name, &infos);
			if ((ISDOTORDOTDOT(entry->d_name) && HASFLAG(AF_ALL))
				|| ((entry->d_name[0] != '.'
					&&  (S_ISREG(infos.st_mode)
						 || S_ISDIR(infos.st_mode)
						 || S_ISLNK(infos.st_mode)))
					|| HASFLAG(AF_ALL)))
			{
				ft_fileadd(&lst
						   , entry->d_name
						   , puid ? puid->pw_name : "root"
						   , guid ? guid->gr_name : "root"
						   , infos.st_mode
						   , infos.st_mtime
						   , infos.st_nlink);
			}
			if (S_ISDIR(infos.st_mode)
				&& (g_flags & AF_RECURSE) != AF_NONE)
				scan_dir(entry->d_name);
		}
		closedir(handle);
	}
	ft_lstdel(&lst, delete_dir);
}

void			print_arg(t_arg *elem)
{
	if (elem)
	{
		if (HASFLAG(AF_VERBOSE))
		{
			PRINT("Scanning ");
			PRINTL(elem->name);
			PRINTL(elem->value);
		}
		scan_dir(elem->name);
	}
}


int				main(int argc, char **argv)
{
	t_arglist	*args;

	args = ft_arglstparse(argc, argv, raise_flag);
	if (LSTEMPTY(args->free))
		scan_dir(".");
	else
		ft_arglstiter(args, print_arg);
	ft_arglstdel(&args);
	return (0);
}
