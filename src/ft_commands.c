#include "ft_commands.h"
#include "ft_file.h"
#include <dirent.h>

void		ft_optset(t_option *opt,
						  char short_name,
						  char *const long_name,
						  t_option_func func,
						  t_bool require_value)
{
	if (!opt)
		return ;
	opt->short_name = short_name;
	opt->long_name = ft_strdup(long_name);
	opt->func = func;
	opt->require_value = require_value;
}

void		ft_optdel(t_option **lst)
{
	if (lst && *lst)
	{
		ft_strdel(&((*lst)->long_name));
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
int	parse_commands(int count, char **array)
{
	char	**p_cur;

	(void)count;
	p_cur = array;
	if (!p_cur)
		return (1);
	ft_dir_scan(*p_cur, filter_func, compare_func);
	return (0);
}

int	parse_errors(int errors)
{
	(void) errors;
	return (0);
}
