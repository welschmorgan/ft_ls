/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:18 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/01 01:52:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_commands.h"
#include "ft_file.h"
#include <dirent.h>

void		ft_optset(t_option *opt,
						  char short_name,
						  char const* long_name,
						  t_option_func func,
						  t_bool require_value,
						  char const* value)
{
	if (!opt)
		return ;
	if (opt->long_name)
		ft_strdel(&opt->long_name);
	if (opt->value)
		ft_strdel(&opt->value);
	opt->short_name = short_name;
	opt->func = func;
	opt->long_name = ft_strdup(long_name ? long_name : "");
	opt->value = ft_strdup(value ? value : "");
	opt->require_value = require_value;
}
t_option	*ft_optnew(char short_name,
					   char const* long_name,
					   t_option_func func,
					   t_bool require_value,
					   char const* value)
{
	t_option *opt;

	opt = ft_memalloc(sizeof(t_option));
	if (!opt)
		return (NULL);
	opt->long_name = NULL;
	opt->value = NULL;
	ft_optset(opt, short_name, long_name, func, require_value, value);
	return opt;
}

void		ft_optdel(void *content, size_t content_size)
{
	t_option	*opt;

	(void)content_size;
	opt = (t_option*)content;
	if (opt)
	{
		ft_strdel(&opt->long_name);
		ft_strdel(&opt->value);
	}
}

#define APP_DESC0	"List information about the FILEs " \
					"(the current directory by default)."
#define APP_DESC1	"Sort entries alphabetically " \
					"if none of -cftuvSUX nor --sort is specified.."
#define APP_DESC2	"Mandatory arguments to long options " \
					"are mandatory for short options too."

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
t_option	*ft_optadd(t_list *list,
			  char short_,
			  char const *long_,
			  t_option_func func,
			  t_bool require_value,
			  char const *value)
{
	t_option	*ret;

	ret = ft_optnew(short_, long_, func, require_value, value);
	ft_lstadd(&list, ft_lstnew(ret, sizeof(t_option)));
	return (ret);
}

int			parse_commands(int count, char **array)
{
	char	**p_cur;
	t_list	*commands;
	t_list	*pcmd;

	commands = ft_lstnew(NULL, 0);
	ft_optadd(commands, 'a', "all", option_dummy, FALSE, "");
	ft_optadd(commands, 'l', "", option_dummy, FALSE, "");
	ft_optadd(commands, 'R', "recursive", option_dummy, FALSE, "");
	ft_optadd(commands, 'r', "reverse", option_dummy, FALSE, "");
	ft_optadd(commands, 't', "", option_dummy, FALSE, "");

	p_cur = array;
	if (!p_cur)
		return (1);
	while (--count)
	{
		if (array[count][0] == '-')
		{
			pcmd = commands;
			while (pcmd)
			{
				if (array[count][1] == '-'
					&& ft_strequ(array[count] + 2, ((t_option*)pcmd)->long_name))
				{
					PRINTL("Found long option");
					((t_option*)pcmd)->func(array[count == 0 ? 0 : (count - 1)]);
				}
				else if (array[count][1] == ((t_option*)pcmd)->short_name)
				{
					PRINTL("Found short option");
					((t_option*)pcmd)->func(array[count == 0 ? 0 : (count - 1)]);
				}
				pcmd = pcmd->next;
			}
		}
	}
	ft_lstdel(&commands, ft_optdel);
	return (0);
}

int	parse_errors(int errors)
{
	(void) errors;
	return (0);
}
