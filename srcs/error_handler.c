/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:26:04 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 21:43:17 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser_param.h"

void    clear_game(game_t *g)
{
    if(g->p->map)
        clear_tab(g->p->map, 0);
    if(g->p)
        free(g->p);
    if(g)
        free(g);
}

void    clear_tab(char **tab, int max)
{
    int i;

    i = 0;
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

void    error_exit(char *msg, game_t *g)
{
    ft_putstr_fd(msg, 2);
    if(g)
        exit(1);
    exit(1);
}