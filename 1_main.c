/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:06:54 by gita              #+#    #+#             */
/*   Updated: 2025/08/01 20:39:25 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int main(int ac, char **av)
{
	t_map	*game_map;
	t_game	game_elem;

	if (ac == 1)
		error_printing("No map was provided X.x\n", NULL);
	if (ac > 2)
		error_printing("Too many maps, cannot choose X.x\n", NULL);
	check_map_extension(av[1]);
	game_map = create_map(av[1]);
	game_elem.map = game_map;
	start_game(&game_elem);
	load_image_n_spread_floor(&game_elem);
	show_instances_on_window(&game_elem);
	// mlx_key_hook(game_elem.window, button_smash, map);
	
	mlx_loop(game_elem.window);
	mlx_terminate(game_elem.window);
	return (0);
}
