/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:59 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 15:51:59 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int     main(int ac, char **av)
{
	game_t	*g;
	int		screen;

	screen = 0;
	g = NULL;
	if(ac == 3 && (ft_strcmp(av[1], "--save") == 0))
		screen = 1;
	if(ac == (2 + screen))
    {
	    if (!(g = (game_t*)malloc(sizeof(game_t))))
		    error_exit("Error: Could'n malloc.\n", g);
	    ft_game(g, screen, av[1 + screen]);
    }
    else
        error_exit("Error: Too much/Too few argument.\n", g);
    return (0);
}
