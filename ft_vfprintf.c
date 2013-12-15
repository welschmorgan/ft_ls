/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 21:54:49 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/15 18:51:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

static t_bool	parse_flags(char const** flag)
{
	if (**flag == '+')
	{
	}
	else if (**flag == '-')
	{
	}
	else if (**flag == ' ')
	{
	}
	else if (**flag == '#')
	{
	}
	else if (**flag == '0')
	{
	}
	else
		return (FALSE);
	(*flag)++;
	return (TRUE);
}

static size_t	parse_width(char const** p)
{
	static char	buf[33];
	char		*ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (p && *p && ft_isdigit(**p))
		*--ptr = *((*p)++);
	if (!*ptr)
		return (0);
	return (ft_atoi(ptr));
}

static int		do_int(int fd, va_list argp)
{
	int		i;
	char	*ret;

	if (!argp)
		return (0);
	i = va_arg(argp, int);
	if (i < 0)
	{
		ret = convert_base(i * -1, 10);
		ft_putchar_fd('-', fd);
		ft_putstr_fd(ret, fd);
		return (ft_strlen(ret) + 1);
	}
	ret = convert_base(i, 10);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret));
}

static int		do_uint(int fd, va_list argp)
{
	unsigned int		i;
	char				*ret;

	if (!argp)
		return (0);
	i = va_arg(argp, unsigned int);
	ret = convert_base(i, 10);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret));
}

static int		do_octal(int fd, va_list argp)
{
	int			i;
	char		*ret;

	i = va_arg(argp, unsigned int);
	ret = convert_base(i, 8);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret));
}

static int		do_string(int fd, va_list argp)
{
	char		*s;

	s = va_arg(argp, char *);
	ft_putstr_fd(s, fd);
	if (!s)
		return (ft_strlen(INVALID_STR));
	return (ft_strlen(s));
}

static int		do_ptr(int fd, va_list argp)
{
	unsigned int	u;
	char			*ret;

	u = va_arg(argp, unsigned int);
	ft_putstr_fd("0x", fd);
	ret = convert_base(u, 10);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret) + 2);
}
static int		do_hexa(int fd, va_list argp)
{
	unsigned int	u;
	char			*ret;

	u = va_arg(argp, unsigned int);
	ret = convert_base(u, 16);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret));
}

static int		do_char(int fd, va_list argp)
{
	char	i;

	i = va_arg(argp, int);
	ft_putchar_fd(i, fd);
	return (1);
}

static int		do_binary(int fd, va_list argp)
{
	unsigned int	u;
	char			*ret;

	u = va_arg(argp, unsigned int);
	ret = convert_base(u, 2);
	ft_putstr_fd(ret, fd);
	return (ft_strlen(ret));
}

static int		do_bool(int fd, va_list argp)
{
	t_bool		b;

	b = va_arg(argp, int);
	ft_putstr_fd(b ? "true" : "false", fd);
	return b ? 4 : 5;
}


int				ft_vfprintf(int fd, const char *fmt, va_list argp)
{
	int			ret;
	char const	*p;
	int			w;

	w = 0;
	p = fmt;
	ret = 0;
	while (p && *p)
	{
		if(*p=='%')
		{
			p++;
			parse_flags(&p);
			w = parse_width(&p);
			if (*p == 'c')
				ret += (do_char(fd, argp));
			else if (*p == 'i' || *p == 'd')
				ret += (do_int(fd, argp));
			else if (*p == 'b')
				ret += (do_bool(fd, argp));
			else if (*p == 'B')
				ret += (do_binary(fd, argp));
			else if (*p == 'o')
				ret += (do_octal(fd, argp));
			else if (*p == 's')
				ret += (do_string(fd, argp));
			else if (*p == 'u')
				ret += (do_uint(fd, argp));
			else if (*p == 'p')
				ret += (do_ptr(fd, argp));
			else if (*p == 'x')
				ret += (do_hexa(fd, argp));
			else
			{
				ft_putchar_fd(*p, fd);
				ret ++;
			}
		}
		else
		{
			ft_putchar_fd(*p, fd);
			ret ++;
		}
		p ++;
	}
	return (ret);
}

size_t	num_len(unsigned int num, int base)
{
	static char buf[33];
	char *ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (1)
	{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	return(ft_strlen(buf));
}

char	*convert_base(unsigned int num, int base)
{
	static char buf[33];
	char *ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (1)
	{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	return(ptr);
}
