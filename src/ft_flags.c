/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 02:57:22 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 11:23:26 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flags.h"
#include "ft_debug.h"

t_flags	g_flags = AF_NONE;

void		print_header(void)
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

void		raise_flags(t_list * elem)
{
	t_argument		*arg;

	if (elem && elem->content)
	{
		arg = (t_argument*)elem->content;
		if (ft_strequ(arg->name, "--verbose") || ft_strequ(arg->name, "-v"))
			SET_FLAG(g_flags, AF_VERBOSE);
		if (ft_strequ(arg->name, "--all") || ft_strequ(arg->name, "-a"))
			SET_FLAG(g_flags, AF_ALL);
		if (ft_strequ(arg->name, "--long") || ft_strequ(arg->name, "-l"))
			SET_FLAG(g_flags, AF_LONG);
		if (ft_strequ(arg->name, "--recursive") || ft_strequ(arg->name, "-R"))
			SET_FLAG(g_flags, AF_RECURSE);
		if (ft_strequ(arg->name, "--reverse") || ft_strequ(arg->name, "-r"))
			SET_FLAG(g_flags, AF_REVERSE);
		if (ft_strequ(arg->name, "-t"))
			SET_FLAG(g_flags, AF_SORT_MODTIME);
	}
}
