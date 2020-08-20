/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:59 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:41:44 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/libft_bonus.h"

int	main(int ac, char **av)
{
	t_game	*g;
	int		screen;

	screen = 0;
	g = NULL;
	if (ac == 3 && (ft_strncmp(av[2], "--save", 7) == 0))
		screen = 1;
	if (ac == (2 + screen))
	{
		if (!(g = (t_game*)malloc(sizeof(t_game))))
			error_exit("Error: Could'n malloc.\n", g);
		bzero(g, sizeof(t_game));
		ft_game(g, screen, av[1]);
	}
	else
		error_exit("Error: Too much/Too few argument.\n", g);
	exit(0);
}
