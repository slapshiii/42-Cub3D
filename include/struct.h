/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:21:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 19:33:01 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define SUCCESS 0
# define ERROR -1

# define CHARSET_MAP " 012NSEW"
# define CHARSET_INMAP "012NSEW"
# define CHARSET_NOTWALL "02NSEW"
# define CHARSET_NOTVALID " \n\0"
# define CHARSET_SPAWN "NSEW"

typedef struct  param_s
{
    int     res_w;
    int     res_h;
    char    *path_no;
    char    *path_so;
    char    *path_we;
    char    *path_ea;
    char    *path_sprite;
    int     color_floor;
    int     color_ceiling;
    char    **map;
}               param_t;

typedef struct  game_s
{
    param_t *p;
}               game_t;

#endif