/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:09 by emollebr          #+#    #+#             */
/*   Updated: 2023/06/06 15:34:14 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_free_tab(char   **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    return ;
}

//searches env for "name", in this case PATH
char    *ft_getenv(char *name, char **env)
{
    int     i;
    int     j;
    char    *sub;

    i = 0;
    while (env[i])
    {
        j = 0;
        while (env[i][j] && env[i][j] != '=')
            j++;
        sub = ft_substr(env[i], 0, j);
        if (ft_strncmp(sub, name, 100) == 0)
        {
           free(sub);
           return (env[i] + j + 1);
        } 
        free(sub);
        i++;
    }
    return (NULL);
}

//searches every path given by env for the command given
char *get_path(char *cmd, char **env)
{
    int     i;
    char    *exec;
    char    **fullpath;
    char    *path_elem;
    char    **s_cmd;

    i = 0;
    fullpath  = ft_split(ft_getenv("PATH", env), ':');
    s_cmd = ft_split(cmd, ' ');
    while (fullpath[i])
    {
        path_elem = ft_strjoin(fullpath[i], "/");
        exec = ft_strjoin(path_elem, s_cmd[0]);
        free(path_elem);
        if (access(exec, F_OK | X_OK) == 0)
            return(ft_free_tab(s_cmd), exec);
        free(exec);
        i++;
    }
    ft_free_tab(fullpath);
    ft_free_tab(s_cmd);
    return (cmd);
}
