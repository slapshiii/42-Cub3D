/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:21:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/03 08:37:08 by phnguyen         ###   ########.fr       */
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
    int     spawn_x;
    int     spawn_y;
    char    spawn_dir;
    char    **map;
    int     max_x;
    int     max_y;
}               param_t;

typedef struct  image_s
{
	void			*img;
	int             *data;
	int				bpp;
	int				sizeline;
	int				endian;
    int             height;
    int             width;
}               image_t;

typedef struct  vect_s
{
    double  x;
    double  y;
}               vect_t;

typedef struct  coord_s
{
    double  x;
    double  y;
}               coord_t;

typedef struct  game_s
{
    param_t     *p;
    void        *mlx_ptr;
    void        *win_ptr;
    void        *win_temp;
    image_t     texture[5];
    image_t     screen;

    coord_t     player;
    vect_t      player_dir;
    double      player_rad;
    vect_t      ray_dir;
    vect_t      plane;

    int         map_x;
    int         map_y;
    vect_t      sidedist;
    vect_t      deltadist;
    double      perpwalldist;
    int         step_x;
    int         step_y;
    int         hit;
    int         side;
    int         col;

    double      step;
    double      tex_pos;
    int         tex_x;
    double      wallx;

    coord_t     coord_to_res;

    uint16_t    key_w:1;
    uint16_t    key_s:1;
    uint16_t    key_a:1;
    uint16_t    key_d:1;
    uint16_t    key_q:1;
    uint16_t    key_e:1;
    uint16_t    remain:10;

}               game_t;

#endif