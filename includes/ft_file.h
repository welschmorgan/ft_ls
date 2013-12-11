/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:27:04 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/12/11 04:34:58 by mwelsch          ###   ########.fr       */
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
	struct stat	*infos;
}				t_file;

/*
 * Reallocates memory for the string, preserves data
 */
char			*ft_strrealloc(char **mem, size_t size);

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
void			print_long_dir(t_file *file, t_bool new_line);
void			print_dir(t_list *lst);


t_file			*ft_fileset(t_file *f,
							const char *name,
							const char *group,
							const char *owner);
t_file			*ft_filenew(const char *name,
							const char *group,
							const char *owner);
void			ft_filedel(void *content, size_t size);

#endif
