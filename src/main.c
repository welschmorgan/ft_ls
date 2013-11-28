#include "ft_commands.h"

int	main(int argc, char **argv)
{
	int err_code;

	if (argc <= 1)
		err_code = usage(APP_NAME);
	err_code = parse_commands(argc -1, argv ++);
	return (parse_errors(err_code));
}
