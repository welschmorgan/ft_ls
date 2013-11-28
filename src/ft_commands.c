#include "ft_commands.h"

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
		ft_strdel(opt->long_name);
		ft_lstdel(lst);
	}
}

int	usage(char const *app_name)
{
	PRINT(app_name);
	PRINT("-------------------------------");
	return (APP_SUCCESS);
}
int	parse_commands(int count, char **array)
{
	char	**p_cur;

	p_cur = array;
	if (!p_cur)
		return (APP_FAILURE);
	while (count)
	{
		DEBUG("Parsing option: ");
		DEBUGL(*p_cur);
		p_cur ++;
	}
	return (APP_SUCCESS);
}

int	parse_errors(int errors)
{
	return (APP_SUCCESS);
}
