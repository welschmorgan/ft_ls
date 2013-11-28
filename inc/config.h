#ifndef CONFIG__H
# define CONFIG__H

# include "libft.h"

# define APP_NAME "ls"

# define ERR_NONE				0
# define ERR_PERMISSION_DENIED	(1 << 1)
# define ERR_FILE_NOT_FOUND		(1 << 2)
# define APP_SUCCES				0
# define APP_FAILURE			1

# define _DEBUG

# define PRINT(msg) ft_putstr(msg)
# define PRINTL(msg) ft_putendl(msg)
# define ERROR(msg) ft_putendl_fd(msg, 2)

# define CODE_FILE "file " __FILE__
# define CODE_LINE " at line " #__LINE__
# define CODE_FUNC " in function " __FUNCTION__
# define CODE_LOCATION CODE_FILE CODE_LINE CODE_FUNC


# ifdef _DEBUG
#  define DEBUG(msg) PRINT(msg)
#  define DEBUGL(msg) PRINTL(msg)
#  define ASSERT_MSG(condition) ERROR("Assert failed: "#condition CODE_LOCATION)
#  define ASSERT(condition) if (!condition) ASSERT_MSG(condition);
# else
#  define DEBUG(msg)
#  define DEBUGL(msg)
#  define ASSERT(condition)
# endif

#endif
