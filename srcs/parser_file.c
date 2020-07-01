/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:34:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/06/30 14:39:03 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_param.h"
#include "get_next_line.h"
#include "cub3d.h"

int parser_file(game_t *g)
{
    if (g)
        if(!(g->texture[0].img = mlx_xpm_file_to_image(g->mlx_ptr, 
            g->p->path_sprite, &(g->texture[0].width), &(g->texture[0].height)))
        || !(g->texture[1].img = mlx_xpm_file_to_image(g->mlx_ptr,
            g->p->path_no, &(g->texture[1].width), &(g->texture[1].height)))
        || !(g->texture[2].img = mlx_xpm_file_to_image(g->mlx_ptr,
            g->p->path_no, &(g->texture[2].width), &(g->texture[2].height)))
        || !(g->texture[3].img = mlx_xpm_file_to_image(g->mlx_ptr,
            g->p->path_no, &(g->texture[3].width), &(g->texture[3].height)))
        || !(g->texture[4].img = mlx_xpm_file_to_image(g->mlx_ptr,
            g->p->path_no, &(g->texture[4].width), &(g->texture[4].height))))
            return (-1); 
    return (0);
}
