/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:37:03 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/04 05:34:23 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_H
# define HUB_H

# include "cub3d.h"

void	init_hud(game_t *g);
void	draw_hp(game_t *g, coord_t coord);
void	update_hp(game_t *g);
void	draw_map(game_t *g);
void	update_map(game_t *g);

void	animate_attack(game_t *g);
void	draw_attack(game_t *g, image_t image);
void	load_images(game_t *g);
void	get_data_image(void *mlx_ptr, image_t image, char *path);

#endif