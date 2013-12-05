/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 23:43:38 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/05 03:18:31 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_file.h"
#include "libopt.h"
#define STR_DEL(x) if (x){ ft_strdel(&x);}
#define PUTFILEBIT(cond,letter) ft_putchar((cond) ? letter : '-');

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

void			print_long_dir(t_file *file)
{
	char		*tmp;

	if (!file)
		return ;
	print_bits(file->mode);
	PRINT(" ");
	ft_putnbr((int)file->nlink);
	PRINT(" ");
	PRINT(file->owner);
	PRINT(" ");
	PRINT(file->group);
	PRINT(" ");
	PRINT(file->name);
	if (S_ISLNK(file->mode))
	{
		tmp = ft_symlink_target(file->name);
		PRINT(ft_strjoin(" -> ",tmp));
		if (tmp)
			ft_strdel(&tmp);
	}
	PRINT(" ");
	PRINT("\n");
}


void			ft_fileadd(t_list **f
						   , const char *name
						   , const char *group
						   , const char *owner
						   , mode_t mode
						   , time_t modif_time
						   , size_t nlink)
{
	t_file		tmp;

	tmp.name = NULL;
	tmp.owner = NULL;
	tmp.group = NULL;
	ft_fileset(&tmp, name, group, owner, mode, modif_time, nlink);
	ft_lstadd(f, ft_lstnew(&tmp, sizeof(t_file)));
}

void			ft_fileset(t_file *f
						   , const char *name
						   , const char *group
						   , const char *owner
						   , mode_t mode
						   , time_t modif_time
						   , size_t nlink)
{
	if (!f)
		return ;
	if (f->name)
		ft_strdel(&f->name);
	if (f->group)
		ft_strdel(&f->group);
	if (f->owner)
		ft_strdel(&f->owner);
	f->name = ft_strdup(name);
	f->group = ft_strdup(group);
	f->owner = ft_strdup(owner);
	f->mode = mode;
	f->mtime = modif_time;
	f->nlink = nlink;
}

t_file			*ft_filenew(const char *name
							, const char *group
							, const char *owner
							, mode_t mode
							, time_t modif_time
							, size_t nlink)
{
	t_file		*f;

	f = ft_memalloc(sizeof(t_file));
	f->name = NULL;
	f->owner = NULL;
	f->group = NULL;
	ft_fileset(f, name, group, owner, mode, modif_time, nlink);
	return (f);
}

void			ft_filedel(t_file **f)
{
	if (!f || !*f)
		return ;
	STR_DEL((*f)->name);
	STR_DEL((*f)->owner);
	STR_DEL((*f)->group);
	ft_memdel((void**)f);
}

char		*ft_strrealloc(char **mem, size_t size)
{
    char *buff;

	buff = ft_strnew(size);
	if(buff)
		ft_strncpy(buff, *mem, size);
	STR_DEL(*mem);
	return (buff);
}

char			*ft_symlink_target(char *filename)
{
	size_t	size = 100;
	char	*buffer = NULL;
	int		nchars;

	while (1)
	{
		buffer = ft_strrealloc (&buffer, size);
		nchars = (int)readlink (filename, buffer, size);
		if (nchars < 0)
		{
			ft_strdel (&buffer);
			return (NULL);
		}
		if (nchars < (int)size)
			return (buffer);
		size *= 2;
	}
	return (buffer);
}
