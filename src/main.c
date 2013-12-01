/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 00:04:12 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/01 00:05:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_commands.h"

int	main(int argc, char **argv)
{
	int err_code;

	if (argc <= 1)
		err_code = usage(APP_NAME);
	err_code = parse_commands(argc, argv);
	return (parse_errors(err_code));
}
