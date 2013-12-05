/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:27:04 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/05 03:13:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE__H
# define FT_FILE__H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_file
{
	char		*name;
	char		*group;
	char		*owner;
	mode_t		mode;
	time_t		mtime;
	size_t		nlink;
}				t_file;

void			ft_fileadd(t_list **f
						   , const char *name
						   , const char *group
						   , const char *owner
						   , mode_t mode
						   , time_t modif_time
						   , size_t nlink);
void			ft_fileset(t_file *f
						   , const char *name
						   , const char *group
						   , const char *owner
						   , mode_t mode
						   , time_t modif_time
						   , size_t nlink);
t_file			*ft_filenew(const char *name
							, const char *group
							, const char *owner
							, mode_t mode
							, time_t modif_time
							, size_t nlink);
void			ft_filedel(t_file **f);

/*
 * Reallocates memory for the string, preserves data
 */
char			*ft_strrealloc(char **mem, size_t size);
void			print_long_dir(t_file *file);

/*
 * Fwd decl - stupid linker complains
 */
ssize_t			readlink (const char *filename, char *buffer, size_t size);
int				lstat(const char *path, struct stat *buf);

/*
 * Extracts the symlink's target name
 */
char			*ft_symlink_target(char *filename);

void			print_bits(mode_t mode);
void			print_long_dir(t_file *file);
void			print_dir(t_list *lst);

#endif
