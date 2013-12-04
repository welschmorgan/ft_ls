/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:12 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/04 17:08:23 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <libopt.h>
#include "main.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>
#include <dirent.h>

#define PRINT ft_putstr
#define PRINTL ft_putendl
#define LSTEMPTY(lst) (!(lst && lst->next))
#define ISDOTORDOTDOT(x) (ft_strequ(x, ".") || ft_strequ(x, ".."))
#define HASFLAG(flag) ((flag & g_flags) != AF_NONE)

typedef struct	s_file
{
	char		*name;
	mode_t		mode;
	time_t		mtime;
}				t_file;

void			ft_fileset(t_file *f, const char *name, mode_t mode, time_t modif_time)
{
	if (!f)
		return ;
	if (f->name)
		ft_strdel(&f->name);
	f->name = ft_strdup(name);
	f->mode = mode;
	f->mtime = modif_time;
}
t_file			*ft_filenew(const char *name, mode_t mode, time_t modif_time)
{
	t_file		*f;

	f = ft_memalloc(sizeof(t_file));
	ft_fileset(f, name, mode, modif_time);
	return (f);
}

void			ft_filedel(t_file **f)
{
	if (!f || !*f)
		return ;
	if ((*f)->name)
		ft_strdel(&(*f)->name);
	ft_memdel((void**)f);
}
t_flags			g_flags = AF_NONE;

void			raise_flag(char *arg, t_uint flags)
{
	printf("Raising flag: %s (%u)\n", arg, flags);
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

void			print_long_dir(t_file *file)
{
	PRINT("-bitflags- \t");
	PRINT(file->name);
	PRINT("\n");
}

void			print_dir(t_list *lst)
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

static void		delete_dir(void *elem, size_t size)
{
	(void)size;
	if (elem)
		ft_strdel((char**)&elem);
}
static void		add_file(t_list **lst, t_file *f)
{
	t_list	*new;

	new = ft_lstnew(f, sizeof(t_file));
	ft_lstadd(lst, new);
}
void			scan_dir(char const *dir)
{
	DIR				*handle;
	struct dirent	*entry;
	struct stat		infos;
	t_list			*lst;

	if ((g_flags & AF_VERBOSE) != AF_NONE)
	{
		PRINT("Scanning directory: ");
		PRINTL(dir);
		PRINT("Show hidden files: ");
		PRINTL(((g_flags & AF_ALL) != AF_NONE) ? "true" : "false");
		PRINT("Long listing format: ");
		PRINTL(((g_flags & AF_LONG) != AF_NONE) ? "true" : "false");
		PRINT("Recursive: ");
		PRINTL(((g_flags & AF_RECURSE) != AF_NONE) ? "true" : "false");
		PRINT("Reversed order: ");
		PRINTL(((g_flags & AF_REVERSE) != AF_NONE) ? "true" : "false");
	}

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

			if (stat(entry->d_name, &infos))
				perror("stat");
			else
			{
				if (ISDOTORDOTDOT(entry->d_name))
				{
					if (HASFLAG(AF_ALL))
						add_file(&lst
								   , ft_filenew(entry->d_name
												, infos.st_mode
												, infos.st_mtime));
				}
				else
				{
					if (S_ISREG(infos.st_mode) || HASFLAG(AF_ALL))
						add_file(&lst
								   , ft_filenew(entry->d_name
												, infos.st_mode
												, infos.st_mtime));
					if (S_ISDIR(infos.st_mode)
						&& (g_flags & AF_RECURSE) != AF_NONE)
						scan_dir(entry->d_name);
				}
			}
		}
		closedir(handle);
	}
	print_dir(lst);
	ft_lstdel(&lst, delete_dir);
}
void			print_arg(t_list *elem)
{
	if (elem && elem->content)
		scan_dir((char*)elem->content);
}


int				main(int argc, char **argv)
{
	t_arglist	*args;

	args = ft_arglstparse(argc, argv, raise_flag);
	if (LSTEMPTY(args->free))
		scan_dir(".");
	else
		ft_lstiter(args->free, print_arg);
	ft_arglstdel(&args);
	return (0);
}
