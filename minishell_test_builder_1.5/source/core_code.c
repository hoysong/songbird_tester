#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "minitester.h"
#include "./put_color/put_color.h"

static inline void pipe_fd(t_info *info)
{
	pipe(info->bash_fd.to_shell);
	pipe(info->bash_fd.from_shell);
	pipe(info->bash_fd.err_from_shell);
	pipe(info->mini_fd.to_shell);
	pipe(info->mini_fd.from_shell);
	pipe(info->mini_fd.err_from_shell);
}

static inline void	close_fd(t_info *info)
{
	close(info->mini_fd.err_from_shell[0]);
	close(info->mini_fd.err_from_shell[1]);
	close(info->mini_fd.from_shell[0]);
	close(info->mini_fd.from_shell[1]);
	close(info->mini_fd.to_shell[0]);
	close(info->mini_fd.to_shell[1]);
	close(info->bash_fd.err_from_shell[0]);
	close(info->bash_fd.err_from_shell[1]);
	close(info->bash_fd.from_shell[0]);
	close(info->bash_fd.from_shell[1]);
	close(info->bash_fd.to_shell[0]);
	close(info->bash_fd.to_shell[1]);
}

static inline void	select_shell(t_info *info, char *shell_name, char **test_case)
{
	pid_t	pid;
	char	*argv[3] = {
		shell_name,
		"-i",
		NULL
	};

	pid = fork();
	if (pid)
	{
		while (*test_case)
		{
			usleep(1000 * 60);
			write(info->fd_now->to_shell[1], *test_case, strlen(*test_case));
			test_case++;
		}
		write(info->fd_now->to_shell[1], "", strlen(""));
		waitpid(pid, NULL, 0);
		/*write eof*/
		write(info->fd_now->err_from_shell[1], "", strlen(""));
		write(info->fd_now->from_shell[1], "", strlen(""));
	}
	else
	{
		dup2(info->fd_now->to_shell[0], 0);
		dup2(info->fd_now->from_shell[1], 1);
		dup2(info->fd_now->err_from_shell[1], 2);
		execve(shell_name, argv, info->env);
		exit(0);
	}
}

static void	show_fd(t_fds *fds)
{
	char	outputs[1024];
	ssize_t	len = 0;

	put_color(BLU_BG, false, " ");
	put_color(BLU, true, " fd: 1");
	printf("\n");
	while (1)
	{
		len = read(fds->from_shell[0], outputs, sizeof(outputs));
		outputs[len] = '\0';
		printf("%s", outputs);
		if ((long unsigned int)len < sizeof(outputs))
			break ;
	}

	put_color(BLU_BG, false, " ");
	put_color(BLU, true, " fd: 2");
	printf("\n");
	while (1)
	{
		len = read(fds->err_from_shell[0], outputs, sizeof(outputs));
		outputs[len] = '\0';
		printf("%s", outputs);
		if ((long unsigned int)len < sizeof(outputs))
			break ;
	}

	printf("\n");
}

static void	diff_fd(t_info *info)
{
	put_color(BLU_BG, true, " bash outputs ");
	printf("\n");
	show_fd(&info->bash_fd);

	put_color(BLU_BG, true, " mini outputs ");
	printf("\n");
	show_fd(&info->mini_fd);
}

void	run_test_case( t_info *info, char **test_case)
{
	char	**test_ptr = test_case;

	if (test_case != NULL)
	{
		put_color(TURQ_BG, true, " Test case is...                                                       ");
		printf("\n");
		while (*test_ptr)
		{
			put_color(TURQ, true, *test_ptr);
			test_ptr++;
		}
		printf("\n");
		pipe_fd(info);
		put_color(TURQ, true, "Testing...\n");

		info->fd_now = &(info->bash_fd);
		select_shell(info, "/usr/bin/bash", test_case);

		info->fd_now = &(info->mini_fd);
		select_shell(info, MINI_LOCATION, test_case);

		put_color(TURQ, true, "DONE!\n");
		diff_fd(info);
		close_fd(info);
	}
}

extern void	start_prog( char **env );
extern int	find_minishell(void);
extern void	show_banner( void );
extern void	test_put_color( void );

int	configure(char **argv, char **env)
{
	write(1, *argv, 0);
	system("clear");
	show_banner();
	sleep(1);
	put_color(TURQ_BG, false, "Finding minishell...\n");
	put_color(TURQ, false, "you can change minishell location with minitester.h header file.\n");
	if (find_minishell() == -1)
		return (-1);
	else
		start_prog(env);
	put_color(TURQ_BG, true, "Test_end\n");
	return (0);
}
