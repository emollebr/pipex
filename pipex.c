/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:43:59 by emollebr          #+#    #+#             */
/*   Updated: 2023/02/28 15:44:01 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;	
	
	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

void	child(char **av, int *pfd, char **env)
{
	int	fd;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		close(pfd[1]);
		perror("error");
		exit (1);
	}
	else
	{
		if (dup2(fd, 0) < 0)
			exit (1);
		dup2(pfd[1], 1);
		close(pfd[0]);
		close(fd);
		execute(av[2], env);
	}
}


void	parent(char **av, int *pfd, char **env)
{
	int	fd;
	fd = open(av[4], O_RDWR | O_CREAT);

	if (fd < 0)
	{
		close(pfd[0]);
		perror("error");
		exit (1);
	}
	else
	{
		dup2(fd, 1);
		dup2(pfd[0], 0);
		close(pfd[1]);
		close(fd);
		execute(av[3], env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pfd[2];
	pid_t	pid1;
	//pid_t	pid2;
	int	status;

	if (ac != 5)
		return (ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2), -1);
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(-1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		return (perror("Fork: "), -1);
		exit(-1);
	}
	/*pid2 = fork();child_two
	printf("%s\n%d\n", "forked pid2", pid2);
	if (pid2 < 0)
	{
		return (perror("Fork: "), -1);
		exit(-1);
	}*/
	if (pid1 == 0)
		child(av, pfd, env);
	waitpid(pid1, &status, 0);
	if (pid1 > 0)
		parent(av, pfd, env);
	//waitpid(pid2, &status, 0);
}
