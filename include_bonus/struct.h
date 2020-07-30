/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:21:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 03:46:17 by phnguyen         ###   ########.fr       */
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

typedef struct  coord_s
{
    double  x;
    double  y;
}               coord_t;

typedef struct  sprite_s
{
    coord_t     pos;
    int         hp;
}               sprite_t;

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
    int     num_sprite;
    sprite_t    *sprite;
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

typedef struct	save_s
{
	int 		size;
	int 		offset;
	int 		header_bytes;
	short int	plane;
	short int	bpixel;
	int			unused;
}				save_t;

typedef struct	bonus_s
{
	image_t		hud;
	image_t		map;
}				bonus_t;

typedef struct  game_s
{
    param_t     *p;
    void        *mlx_ptr;
    image_t     win_img;
    void        *win_temp;
    image_t     texture[5];
    image_t     screen;
	int			save;

    coord_t     player;
    vect_t      player_dir;
    vect_t      plane;
	double		speed;

    vect_t      ray_dir;
	int			mapx;
	int			mapy;
	vect_t		sidedist;
	vect_t		deltdist;
	double		perp;
	vect_t		step;
	int			side;
	int			lineheight;
	int			dstart;
	int			dend;

    double      tex_pos;
    int         tex_x;
    int         tex_y;
    double      wallx;
    image_t     texture_side;

    double      *zbuffer;
    int         sprite_h;
    int         sprite_w;
	int			sprite_screen;
    coord_t     s;
    coord_t     trans;
	int			movscreen;

	vect_t		raydirz;
	vect_t		raydiro;
	float		rowdist;
	vect_t		floorstep;
	vect_t		floor;
	image_t		texture_floor;
	image_t		texture_ceil;

    int         y;
    int         x;
	
    uint16_t    key_w:1;
    uint16_t    key_s:1;
    uint16_t    key_a:1;
    uint16_t    key_d:1;
    uint16_t    key_q:1;
    uint16_t    key_e:1;
	uint16_t    key_x:1;
	uint16_t    key_shift:1;
    uint16_t    remain:8;

	bonus_t		*bonus;
	double		pitch;
	double		posz;
	int			is_floor;
}               game_t;

#endif