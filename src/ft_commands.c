/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:18 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/01 07:26:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_commands.h"
#include "ft_file.h"
#include <stdio.h>

int			usage(char const *app_name)
{
	PRINT("Usage: ");
	PRINT(app_name);
	PRINTL("[OPTION]... [FILE]...");
	PRINTL(APP_DESC0);
	PRINTL(APP_DESC1);
	PRINTL("");
	PRINTL(APP_DESC2);
	PRINTL("\t-a, --all\tdo not ignore entries starting with .");
	PRINTL("\t-l\t\tuse a long listing format");
	PRINTL("\t-R, --recursive\tlist subdirectories recursively");
	PRINTL("\t-r, --reverse\treverse order while sorting");
	PRINTL("\t-t\t\tsort by modification time, newest first");
	return (0);
}

int			option_dummy(char const *f)
{
	(void)*f;
	ft_putendl("Dummy option");
	return (0);
}
typedef enum		e_app_flag
{
	AF_NONE,
	AF_ALL = 1 << 1,
	AF_LONG = 1 << 2,
	AF_RECURSIVE = 1 << 3,
	AF_REVERSE = 1 << 4,
	AF_SORT_MODTIME = 1 << 5,
	AF_VERBOSE		= 1 << 6
}					t_app_flag;

t_uint				g_app_flags = AF_NONE;

# define APP_CHECK_FLAGS(f) ((f & g_app_flags) != AF_NONE)

#include <dirent.h>


int			do_scan(char const *dirname)
{
	if ((g_app_flags & AF_VERBOSE) != AF_NONE)
	{
		PRINT("Scanning directory ");
		PRINTL(dirname);
		if (APP_CHECK_FLAGS(AF_ALL))
			PRINTL("Showing hidden files");
		if (APP_CHECK_FLAGS(AF_LONG))
			PRINTL("Long listing format");
		PRINT("Recurse into subdirectories: "); PRINTL(APP_CHECK_FLAGS(AF_LONG) ? "true" : "false");
		PRINT("Sort by last modification date: "); PRINTL(APP_CHECK_FLAGS(AF_SORT_MODTIME) ? "true" : "false");
	}
	return (0);
}
int			check_command(char const *dirname)
{
	if (ft_strequ(dirname, "a") || ft_strequ(dirname, "-all"))
		g_app_flags |= AF_ALL;
	else if (ft_strequ(dirname, "l"))
		g_app_flags |= AF_LONG;
	else if (ft_strequ(dirname, "R") || ft_strequ(dirname, "-recursive"))
		g_app_flags |= AF_RECURSIVE;
	else if (ft_strequ(dirname, "r") || ft_strequ(dirname, "-reverse"))
		g_app_flags |= AF_REVERSE;
	else if (ft_strequ(dirname, "v") || ft_strequ(dirname, "-verbose"))
		g_app_flags |= AF_VERBOSE;
	else if (ft_strequ(dirname, "t"))
		g_app_flags |= AF_SORT_MODTIME;
	else
		return (do_scan(dirname));
	return (1);
}
int			parse_commands(int count, char **array)
{
	char	**p_cur;
	char	*p_tmp;
	char	*dir;

	p_cur = array + 1;
	if (!p_cur)
		return (1);
	while (--count)
	{
		if ((*p_cur)[0] == '-')
		{
			p_tmp = ft_strdup((*p_cur));
			check_command(p_tmp);
			ft_strdel(&p_tmp);
		}
		else
		{
			dir = ft_strdup((*p_cur));
			do_scan(dir);`
			ft_strdel(&dir);
		}
		p_cur ++;
	}
	return (0);
}

int		parse_errors(int errors)
{
	(void) errors;
	return (0);
}
