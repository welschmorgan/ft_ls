/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 00:18:50 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/05 03:36:47 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_DEBUG__H
# define FT_DEBUG__H

# include <libft.h>

# define TXT(x) #x

# define PRINTNB_FD(nb, fd) ft_putnbr_fd(nbr, fd)
# define PRINTNBL_FD(nb, fd) ft_putnbr_fd(nbr, fd); ft_putendl_fd("")
# define PRINTNB(nb) PRINTNB_FD(nb, 1)
# define PRINTNBL(nb) PRINTNBL_FD(nb, 1)

# define PRINT_FD(x, fd) ft_putstr_fd(x, fd)
# define PRINT(x) PRINT_FD(x, 1)

# define PRINTL_FD(x, fd) ft_putendl_fd(x, fd)
# define PRINTL(x) PRINTL_FD(x, 1)

# ifdef _DEBUG
#  define DEBUG(msg) PRINT(msg)
#  define DEBUGL(msg) PRINTL(msg)
#  define DEBUGNB(nb) PRINTNB(nb)
#  define DEBUGNBL(nb) PRINTNBL(nb)
# else
#  define DEBUG(msg)
#  define DEBUGL(msg)
#  define DEBUGNB(nb)
#  define DEBUGNBL(nb)
# endif

# define TRACE DEBUGL(__FUNCTION__)

#endif /* !FT_DEBUG__H */
