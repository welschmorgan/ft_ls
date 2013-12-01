/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkboss </var/mail/darkboss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 22:22:31 by darkboss          #+#    #+#             */
/*   Updated: 2013/12/01 03:05:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG__H
# define CONFIG__H

# include <libft.h>

# define APP_NAME		"ls"
# define ERR_MAXLEN		256
# define MAX_PATH 260

typedef enum			e_app_error
{
	AE_SUCCESS,
	AE_ERROR,
	AE_PERMISSION_DENIED,
	AE_FILE_NOT_FOUND
}						t_app_error;

#define APP_DESC0	"List information about the FILEs " \
					"(the current directory by default)."
#define APP_DESC1	"Sort entries alphabetically " \
					"if none of -cftuvSUX nor --sort is specified.."
#define APP_DESC2	"Mandatory arguments to long options " \
					"are mandatory for short options too."

extern t_app_error		g_last_error;

char					*ft_tr_error(t_app_error e);

void					ft_putloc_fd(char const *msg, int fd);
void					ft_putloc(char const *msg);

# define PRINT(msg)		ft_putstr(msg)
# define PRINTL(msg)	ft_putendl(msg)
# define ERROR(msg)		ft_putloc_fd(msg, 2)

# ifdef _DEBUG
#  define TRACE_FUNC ft_putloc_fd("Trace :-> ", 2)
#  define DEBUG(msg) PRINT("[DEBUG] " msg)
#  define DEBUGL(msg) PRINTL("[DEBUG] " msg)
# else
#  define DEBUG(msg)
#  define DEBUGL(msg)
#  define TRACE_FUNC
# endif
#endif
