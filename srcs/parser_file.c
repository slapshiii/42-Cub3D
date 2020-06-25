/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:34:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/06/25 16:49:33 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_param.h"
#include "get_next_line.h"
#include "cub3d.h"

int parser_file(game_t *g)
{
    if (g)
        if(!(g->texture[0].img = mlx_xpm_file_to_image(g->mlx_ptr, g->p->path_sprite, &(g->texture->width), &(g->texture->height))))
            return (-1);
        if(!(g->texture[1].img = mlx_xpm_file_to_image(g->mlx_ptr, g->p->path_no, &(g->texture->width), &(g->texture->height))))
            return (-1);
        if(!(g->texture[2].img = mlx_xpm_file_to_image(g->mlx_ptr, g->p->path_so, &(g->texture->width), &(g->texture->height))))
            return (-1);
        if(!(g->texture[3].img = mlx_xpm_file_to_image(g->mlx_ptr, g->p->path_we, &(g->texture->width), &(g->texture->height))))
            return (-1);
        if(!(g->texture[4].img = mlx_xpm_file_to_image(g->mlx_ptr, g->p->path_ea, &(g->texture->width), &(g->texture->height))))
            return (-1);
    return (0);
}
