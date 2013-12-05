/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 15:03:24 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/05 03:13:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN__H
# define MAIN__H

typedef enum	e_app_flags
{
	AF_NONE,
	AF_VERBOSE = 1 << 1,
	AF_LONG = 1 << 2,
	AF_REVERSE = 1 << 3,
	AF_RECURSE = 1 << 4,
	AF_ALL = 1 << 5,
	AF_SORT_MODTIME = 1 << 6
}				t_app_flags;

typedef t_uint	t_flags;

extern t_flags	g_flags;
void			print_dir(t_list *lst);

#endif
