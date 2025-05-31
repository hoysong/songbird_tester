#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "minitester.h"
#include "./put_color/put_color.h"

static int	type_chk(__mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		return (1);
	if ((mode & S_IFMT) == S_IFREG)
	{
		if ((mode & S_IXGRP) == S_IXGRP
			&& (mode & S_IXUSR) == S_IXUSR
			&& (mode & S_IXOTH) == S_IXOTH)
			return (3);
		else
			return (2);
	}
	return (0);
}

static int	get_file_type(char *argv)
{
	int			return_code;
	struct stat	stat_buf;

	return_code = 0;
	return_code = stat(argv, &stat_buf);
	if (return_code != 0)
	{
		if (errno == 20)
			return (4);
		else
			return (0);
	}
	return (type_chk(stat_buf.st_mode));
}

/* this function return -1 if minishell is not exist. */
int	find_minishell( void )
{
	int	err_num = get_file_type(MINI_LOCATION);
	if (err_num != 3)
	{
		put_color(RED, true, "ERR: program minishell not found.\n");
		put_color(TURQ, false, "├─note: locate songbird_tester repository in your minishell directory.\n");
		put_color(TURQ, false, "└─note: your program name must be minishell.\n");
//		put_color(TURQ, false, "note: you can change your minishell directory with modifying header named minitester.h \n");
		return (-1);
	}
	else
		put_color(TURQ, true, "minishell found!\n");
	printf("\n");
	return (1);
}
