/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:37:03 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 06:24:51 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_H
# define HUB_H

# include "cub3d.h"

void	init_hud(game_t *g);
void	draw_hud(game_t *g);
void	draw_map(game_t *g);
void	update_map(game_t *g);

#endif