/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 23:43:38 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/06 11:55:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_file.h"
#include "ft_debug.h"
#include "ft_memrealloc.h"

#define STR_DEL(x) if (x){ ft_strdel(&x);}
#define PUTFILEBIT(cond,letter) ft_putchar((cond) ? letter : '-')

void			print_bits(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else
		ft_putchar('-');
	PUTFILEBIT(mode & S_IRUSR, 'r');
	PUTFILEBIT(mode & S_IWUSR, 'w');
	PUTFILEBIT(mode & S_IXUSR, 'x');
	PUTFILEBIT(mode & S_IRGRP, 'r');
	PUTFILEBIT(mode & S_IWGRP, 'w');
	PUTFILEBIT(mode & S_IXGRP, 'x');
	PUTFILEBIT(mode & S_IROTH, 'r');
	PUTFILEBIT(mode & S_IWOTH, 'w');
	PUTFILEBIT(mode & S_IXOTH, 'x');
}

char			*ft_symlink_target(char *filename)
{
	size_t		size;
	int			nchars;
	char		*buffer;

	size = 100;
	buffer = NULL;
	while (1)
	{
		buffer = ft_memrealloc(buffer, sizeof(char) * size);
		nchars = readlink(filename, buffer, size);
		if (nchars < 0)
		{
			if (buffer)
				ft_strdel(&buffer);
			return (NULL);
		}
		if (nchars < (int)size)
			return (buffer);
		size *= 2;
	}
}

void			print_long_dir(t_file *file)
{
	char		*tmp;

	if (!file)
		return ;
	print_bits(file->infos->st_mode);
	PRINT(" ");
	ft_putnbr((int)file->infos->st_nlink);
	PRINT(" ");
	PRINT(file->owner);
	PRINT(" ");
	PRINT(file->group);
	PRINT(" ");
	ft_putnbr((int)file->infos->st_size);
	PRINT(" ");
	PRINT(file->name);
	if (S_ISLNK(file->infos->st_mode))
	{
		tmp = ft_symlink_target(file->name);
		PRINT(ft_strjoin(" -> ",tmp));
		if (tmp)
			ft_strdel(&tmp);
	}
	PRINT(" ");
	PRINT("\n");
}


t_file			*ft_fileset(t_file *f,
							const char *name,
							const char *group,
							const char *owner)
{
	if (!f)
		return (f);
	if (f->name)
		ft_strdel(&f->name);
	if (f->group)
		ft_strdel(&f->group);
	if (f->owner)
		ft_strdel(&f->owner);
	f->name = ft_strdup(name);
	f->group = ft_strdup(group);
	f->owner = ft_strdup(owner);
	return (f);
}

t_file			*ft_filenew(const char *name,
							const char *group,
							const char *owner)
{
	t_file	*ret;

	ret = ft_memalloc(sizeof(t_file));
	ret->name = NULL;
	ret->group = NULL;
	ret->owner = NULL;
	ret->infos = ft_memalloc(sizeof(struct stat));
	ft_fileset(ret, name, group, owner);
	return (ret);
}

void			ft_filedel(void *content, size_t size)
{
	t_file	*file;

	(void)size;
	if (content)
	{
		file = (t_file*)content;
		ft_strdel(&file->name);
		ft_strdel(&file->group);
		ft_strdel(&file->owner);
		ft_memdel((void**)&file->infos);
	}
}
