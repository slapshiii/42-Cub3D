/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:37:03 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 01:58:45 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_H
# define HUB_H

# define BLK 0x0
# define WHT 0xFFFFFF
# define BLU 0x263D63
# define RED 0xBA202F

# define FLOOR_PATH "texture/grass.xpm"
# define CEILING_PATH "texture/stone.xpm"
# define HEALTH_PATH "texture/coeur.xpm"
# define ENDSCREEN_PATH "texture/fb.xpm"
# define STARTSCREEN_PATH "texture/fb.xpm"
# define ATTACK_F1_PATH "texture/attack/frame1.xpm"
# define ATTACK_F2_PATH "texture/attack/frame2.xpm"
# define ATTACK_F3_PATH "texture/attack/frame3.xpm"
# define ATTACK_F4_PATH "texture/attack/frame4.xpm"
# define ATTACK_F5_PATH "texture/attack/frame5.xpm"
# define PLAY_MUSIC "afplay music/cat.mp3 &"

# include "cub3d.h"

void	init_hud(game_t *g);
void	draw_hp(game_t *g, coord_t coord, int size);
void	update_hp(game_t *g);
void	draw_map(game_t *g);
void	update_map(game_t *g);

void	animate_attack(game_t *g);
void	draw_attack(game_t *g, image_t image);
void	load_images(game_t *g);
void	get_data_image(void *mlx_ptr, image_t *image, char *path);

void	end_game(game_t *g);
void	start_game(game_t *g);

#endif