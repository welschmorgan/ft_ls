/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 22:27:26 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/01 01:44:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMANDS__H
# define FT_COMMANDS__H

# include "ft_config.h"

typedef int (*t_option_func)(char const *);
typedef struct	e_option
{
	char			short_name;
	char			*long_name;
	t_option_func	func;
	t_bool			require_value;
	char			*value;
	struct e_option	*next;
}				t_option;

t_option	*ft_optnew(char short_name,
					   char const* long_name,
					   t_option_func func,
					   t_bool require_value,
					   char const* value);
void		ft_optdel(void *content, size_t content_size);
void		ft_optset(t_option *opt,
						  char short_name,
						  char const* long_name,
						  t_option_func func,
						  t_bool require_value,
						  char const* value);

t_list		*ft_optlstnew(void (*init_func)(t_list **));
void		ft_optlstdel(t_list **lst);

int			usage(char const *app_name);
int			parse_commands(int count, char **array);
int			parse_errors(int errors);

#endif
