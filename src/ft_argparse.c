/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:54:17 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/11 04:22:42 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_debug.h"

static char		*skip_until(const char *s, char c)
{
	while (s && *s && *s != c)
		s ++;
	return (ft_strdup(((*s != '\0') ? ++s : s)));
}

static char		*copy_until(const char *s, char c)
{
	char	*ptr;
	char	*buf;

	buf = ft_strdup(s);
	if (!buf)
		return (NULL);
	ptr = buf;
	while (ptr && *ptr && *ptr != c)
		ptr ++;
	*ptr = '\0';
	return (buf);
}
static void		add_arg(t_list **lst, char *str)
{
	char		*ptr;
	char		buf[3];
	t_flags		flags;

	if (!str)
		return ;
	if (str[0] == '-' && str[1] != '-')
	{
		ptr = str + 1;
		buf [2] = '\0';
		buf [0] = '-';
		while (*ptr)
		{
			buf[1] = *ptr;
			ft_argadd(lst,
					  buf,
					  "",
					  AT_SHORT);
			ptr ++;
		}
	}
	else
	{
		flags = ft_strchr(str, '=') ? AT_VALUE : AT_NONE;
		flags |= ((str[0] == '-' && str[1] == '-')
				  ? AT_LONG
				  : ((str[0] == '-')
					 ? AT_SHORT
					 : AT_FREE));
		ft_argadd(lst,
				  copy_until(str, '='),
				  skip_until(str, '='),
				  flags);
	}
}
t_list			*ft_argparse(int c, char **r)
{
	t_list		*l;
	int   		i;

	TRACE;
	i = 1;
	l = ft_lstnew(NULL, 0);
	while (i < c)
	{
		add_arg(&l, r[i]);
		i ++;
	}
	return (l);
}
