/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:39:15 by phnguyen          #+#    #+#             */
/*   Updated: 2020/06/30 17:48:06 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser_param.h"
# include "libft.h"
# include "struct.h"
# include <mlx.h>
//# include <X11/X.h>

void    clear_path(param_t *p);
void    clear_game(game_t *g);
void    clear_tab(char **tab, int max);
void    error_exit(char *msg, game_t *g);
void    ft_game(game_t *g, int screen, char *path);

int     make_window(game_t *g);

#endif
