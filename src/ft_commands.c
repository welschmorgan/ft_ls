/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:18 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/01 01:23:04 by mwelsch          ###   ########.fr       */
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
	opt->short_name = short_name;
	opt->long_name = ft_strdup(long_name ? long_name : "");
	opt->func = func;
	opt->value = ft_strdup(value ? value : "");
	opt->require_value = require_value;
}

void		ft_optdel(t_option **lst)
{
	if (lst && *lst)
	{
		ft_strdel(&((*lst)->long_name));
		ft_strdel(&((*lst)->value));
		ft_memdel((void**)lst);
		*lst = NULL;
	}
}

#define APP_DESC0	"List information about the FILEs " \
					"(the current directory by default)."
#define APP_DESC1	"Sort entries alphabetically " \
					"if none of -cftuvSUX nor --sort is specified.."
#define APP_DESC2	"Mandatory arguments to long options " \
					"are mandatory for short options too."

int	usage(char const *app_name)
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
int filter_func(const struct dirent *a)
{
	(void) a;
	return (1);
}
int compare_func(const struct dirent **a, const struct dirent **b)
{
	return (strcmp((*a)->d_name, (*b)->d_name));
}

int	option_dummy(char const *f)
{
	(void)*f;
	ft_putendl("Dummy option");
	return (0);
}
# define PUSH_OPT_(list,short_name,long_name,pfn,req_args,val) \
	ft_optnew(short_name, long_name, pfn, req_args, val), sizeof(t_option)
# define PUSH_OPT(list,short_name,long_name,pfn,req,val)	\
	ft_lstadd(&list,ft_lstnew(PUSH_OPT_(list,short_name,long_name,pfn,req,val)))

t_option	ft_optadd(t_list *list,
			  char short_,
			  char const *long_,
			  t_option_func func,
			  t_bool require_value,
			  char const *value)
{
	t_list	*ret;

	ret = ft_lstnew(NULL, 0);
	ft_strcat(
	if (!list)
		return (NULL);
	return (ft_lstadd(&list,
}
int	parse_commands(int count, char **array)
{
	char	**p_cur;
	t_list	*commands;
	t_list	*pcmd;
	char	**split;

	commands = ft_lstnew(NULL, 0);
	PUSH_OPT(&commands, 'a', "all", option_dummy, FALSE, "");
	PUSH_OPT(&commands, 'l', "", option_dummy, FALSE, "");
	PUSH_OPT(&commands, 'R', "recursive", option_dummy, FALSE, "");
	PUSH_OPT(&commands, 'r', "reverse", option_dummy, FALSE, "");
	PUSH_OPT(&commands, 't', "", option_dummy, FALSE, "");

	p_cur = array;
	if (!p_cur)
		return (1);
	while (--count)
	{
		if (array[count][0] = '-')
		{
			pcmd = commands;
			while (pcmd)
			{
				if (array[count][1] == '-'
					&& ft_strequ(array[count] + 2, pcmd->long_name))
					pcmd->func(array[count == 0 ? 0 : (count - 1)]);
				else if (array[count][1] == pcmd->short_name)
					pcmd->func(array[count == 0 ? 0 : (count - 1)]
				pcmd = pcmd->next;
			}
		}
	}
	ft_lstdel(&commands);
	return (0);
}

int	parse_errors(int errors)
{
	(void) errors;
	return (0);
}
