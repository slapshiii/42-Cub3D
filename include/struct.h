/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 17:21:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 23:38:55 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>

# define SUCCESS 0
# define ERROR -1

# define CHARSET_MAP " 012NSEW"
# define CHARSET_INMAP "012NSEW"
# define CHARSET_NOTWALL "02NSEW"
# define CHARSET_NOTVALID " \n\0"
# define CHARSET_SPAWN "NSEW"

typedef struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct	s_sprite
{
	t_coord		pos;
	int			id;
}				t_sprite;

typedef struct	s_param
{
	int			res_w;
	int			res_h;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_sprite;
	int			color_floor;
	int			color_ceiling;
	int			spawn_x;
	int			spawn_y;
	char		spawn_dir;
	char		**map;
	int			max_x;
	int			max_y;
	int			num_sprite;
	t_sprite	*sprite;
}				t_param;

typedef struct	s_image
{
	void			*img;
	int				*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				height;
	int				width;
}				t_image;

typedef struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_save
{
	int			size;
	int			offset;
	int			header_bytes;
	short int	plane;
	short int	bpixel;
	int			unused;
}				t_save;

typedef struct	s_game
{
	t_param		*p;
	void		*mlx_ptr;
	t_image		win_img;
	void		*win_temp;
	t_image		texture[5];
	t_image		screen;
	int			save;

	t_coord		player;
	t_vect		player_dir;
	t_vect		plane;

	t_vect		ray_dir;
	int			mapx;
	int			mapy;
	t_vect		sidedist;
	t_vect		deltdist;
	double		perp;
	t_vect		step;
	int			side;
	int			lineheight;
	int			dstart;
	int			dend;

	double		tex_pos;
	int			tex_x;
	int			tex_y;
	double		wallx;
	t_image		texture_side;

	double		*zbuffer;
	int			sprite_h;
	int			sprite_w;
	int			sprite_screen;
	t_coord		s;
	t_coord		trans;

	int			y;
	int			x;

	int			mouse_x;
	uint16_t	key_w:1;
	uint16_t	key_s:1;
	uint16_t	key_a:1;
	uint16_t	key_d:1;
	uint16_t	key_q:1;
	uint16_t	key_e:1;
	uint16_t	remain:10;

}				t_game;

#endif
