/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DarkBoss <mwelsch@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 22:54:17 by DarkBoss          #+#    #+#             */
/*   Updated: 2013/11/30 11:35:44 by DarkBoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

t_app_error	g_last_error = AE_SUCCESS;

void		ft_check_err_cpy(t_app_error a
						  , t_app_error b
						  , char **dest
						  , const char *src)
{
	if (a == b)
		ft_strncpy(*dest, src, ERR_MAXLEN);
}

char		*ft_tr_error(t_app_error e)
{
	char		*ret;

	ret = ft_strnew(ERR_MAXLEN);
	ft_check_err_cpy(e, AE_SUCCESS, &ret, "Success");
	ft_check_err_cpy(e, AE_ERROR, &ret, "Error");
	ft_check_err_cpy(e, AE_PERMISSION_DENIED, &ret, "Permission denied");
	ft_check_err_cpy(e, AE_FILE_NOT_FOUND, &ret, "File not found");
	return (ret);
}

void					ft_putloc_fd(char const *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	ft_putstr_fd(" in function: ", fd);
	ft_putstr_fd(__FUNCTION__, fd);
}

void					ft_putloc(char const *msg)
{
	ft_putloc_fd(msg, 1);
}
