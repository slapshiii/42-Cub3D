/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:53:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/16 15:21:56 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser_param.h"

int get_data(game_t *g)
{
    if (!(g->d = (data_t*)malloc(sizeof(data_t))))
        return (0);
    bzero(g->d, sizeof(data_t));
    g->d->mlx_ptr = mlx_init();
    if(!(g->d->img_ptr[0] = mlx_xpm_file_to_image(g->d->mlx_ptr, g->p->path_no, 0, 0)))
        return (0);
    return (1);
}
