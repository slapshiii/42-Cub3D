/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 21:49:16 by phnguyen         ###   ########.fr       */
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
        split = ft_split(tab[i], ' ');
        if (split[0])
        {
            // if(check_param(split, g->p) == 0)
            //     {};
            // else if(check_map(tab, g->p, i) == 0)
            //     return (check_config(g->p));
            // else
            // {
            //     clear_tab(split, 0);
            //     return (1);
            // }
            clear_tab(split, 0);
        }
        if (split)
            free(split);
        i++;
    }
    return (0);
}

int parser_param(game_t *g, char *path)
{
    char    *temp[255];
    int     fd;
    int     i;

    i = 0;
    if ((fd = open(path, O_RDONLY)) >= 0)
        if ((g->p = (param_t*)malloc(sizeof(param_t))))
        {
            ft_bzero(g->p, sizeof(param_t));
            while(get_next_line(fd, &temp[i]) > 0)
                i++;
            if (check_file(temp, i, g) == 0)
            {
                clear_tab(temp, i);
                return(0);
            }
            clear_tab(temp, i);
        }
    return(1);
}