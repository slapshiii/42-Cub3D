/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 17:56:18 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_param.h"
#include "get_next_line.h"
#include "cub3d.h"

int check_file(char **tab, int index, game_t *g)
{
    int     i;
    char    **split;

    i = 0;
    while (i <= index)
    {
        split = ft_split(tab[i]);
    }
}

int parser_param(game_t *g, char *path)
{
    char    *temp[255];
    char    *str;
    int     fd;
    int     i;
    int     max;

    i = 0;
    if ((fd = open(path, O_RDONLY)) >= 0)
        if ((g->p = (param_t*)malloc(sizeof(param_t))))
        {
            while(get_next_line(fd, &str) > 0)
            {
                temp[i] = ft_strdup(str);
                free(str);
                i++;
            }
            temp[i] = ft_strdup(str);
            free(str);
            if (check_file(temp, i, g) == 0)
                return(0);
        }
    return(1);
}