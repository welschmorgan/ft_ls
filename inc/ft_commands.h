#ifndef FT_COMMANDS__H
# define FT_COMMANDS__H

# include "config.h"

typedef int (*t_option_func)(char const *);
typedef struct	e_option
{
	char			short_name;
	char			*long_name;
	t_option_func	func;
	t_bool			require_value;
	struct e_option	*next;
}				t_option;

t_option	*ft_optnew(char short_name,
					   char *const long_name,
					   t_option_func func,
					   t_bool require_value);
void		ft_optdel(t_option **opt);
void		ft_optset(t_option *opt,
						  char short_name,
						  char *const long_name,
						  t_option_func func,
						  t_bool require_value);

t_list		*ft_optlstnew(void (*init_func)(t_list **));
void		ft_optlstdel(t_list **lst);

int			usage(char const *app_name);
int			parse_commands(int count, char **array);
int			parse_errors(int errors);

#endif