/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:43:48 by emollebr          #+#    #+#             */
/*   Updated: 2023/02/28 15:43:50 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "my_lib.h"
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
#include <sys/wait.h>

void	parent(char **av, int *pfd, char **env);
void	child(char **av, int *pfd, char **env);
void	execute(char *cmd, char **env);

char *get_path(char *cmd, char **env);
char    *ft_getenv(char *name, char **env);
void    ft_free_tab(char   **tab);


#endif
