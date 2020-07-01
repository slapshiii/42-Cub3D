/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:26:04 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/16 13:56:21 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser_param.h"

void    clear_path(param_t *p)
{
    if(p->path_no)
        free(p->path_no);
    if(p->path_so)
        free(p->path_so);
    if(p->path_we)
        free(p->path_we);
    if(p->path_ea)
        free(p->path_ea);
    if(p->path_sprite)
        free(p->path_sprite);
    if(p->map)
        clear_tab(p->map, 0);
}

void    clear_game(game_t *g)
{
    if(g)
    {
        if(g->p)
        {
            clear_path(g->p);
            free(g->p);
        }
        free(g);
        if(g->d)
        {
            
        }
    }
}

void    clear_tab(char **tab, int max)
{
    int i;

    i = 0;
    if(tab)
    {
        if(max > 0)
            while (i <= max)
            {
                free(tab[i]);
                i++;
            }
        else
        {
            while (tab[i])
            {
                free(tab[i]);
                i++;
            }
            free(tab);
        }
    }
}

void    error_exit(char *msg, game_t *g)
{
    ft_putstr_fd(msg, 2);
    clear_game(g);
    exit(1);
}