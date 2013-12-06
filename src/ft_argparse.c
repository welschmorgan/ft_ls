/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:54:17 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 10:01:36 by mwelsch          ###   ########.fr       */
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

t_list			*ft_argparse(int c, char **r)
{
	t_list		*l;
	int   		i;
	t_flags		flags;

	TRACE;
	i = 1;
	l = ft_lstnew(NULL, 0);
	while (i < c)
	{
		flags = ft_strchr(r[i], '=') ? AT_VALUE : AT_NONE;
		flags |= ((r[i][0] == '-' && r[i][1] == '-')
				  ? AT_LONG
				  : ((r[i][0] == '-')
					 ? AT_SHORT
					 : AT_FREE));
		ft_argadd(&l, copy_until(r[i], '='), skip_until(r[i], '='), flags);
		i ++;
	}
	return (l);
}
