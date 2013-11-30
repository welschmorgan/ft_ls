/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkboss </var/mail/darkboss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 22:22:31 by darkboss          #+#    #+#             */
/*   Updated: 2013/11/30 11:36:12 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG__H
# define CONFIG__H

# include <libft.h>

# define APP_NAME		"ls"
# define ERR_MAXLEN		256
# define MAX_PATH 260
# define _DEBUG

typedef enum			e_app_error
{
	AE_SUCCESS,
	AE_ERROR,
	AE_PERMISSION_DENIED,
	AE_FILE_NOT_FOUND
}						t_app_error;

extern t_app_error		g_last_error;

char					*ft_tr_error(t_app_error e);

void					ft_putloc_fd(char const *msg, int fd);
void					ft_putloc(char const *msg);

# define PRINT(msg)		ft_putstr(msg)
# define PRINTL(msg)	ft_putendl(msg)
# define ERROR(msg)		ft_putloc_fd(msg, 2)

struct dirent;

typedef int(*ft_file_compare)(const struct dirent **, const struct dirent **);
typedef int(*ft_file_filter)(const struct dirent *);

# ifdef _DEBUG
#  define TRACE_FUNC ft_putloc_fd("Trace :-> ", 2)
# else
#  define TRACE_FUNC
# endif
#endif
